#include "infiniband/driver.h"
#include "infiniband/ib_user_ioctl_verbs.h"
#include <stdio.h>
#include <stdlib.h>

#include "phoenix.h"
#include "phoenix-abi.h"
#include "phoenix_verbs.h"

static const struct verbs_context_ops phoenix_context_ops = {
	.alloc_pd = phoenix_alloc_pd,
	.cq_event = phoenix_cq_event,
	.create_cq = phoenix_create_cq,
	.create_qp = phoenix_create_qp,
	.dealloc_pd = phoenix_free_pd,
	.dereg_mr = phoenix_dereg_mr,
	.destroy_cq = phoenix_destroy_cq,
	.destroy_qp = phoenix_destroy_qp,
	.free_context = phoenix_free_context,
	.modify_qp = phoenix_modify_qp,
	.poll_cq = phoenix_poll_cq,
	.post_recv = phoenix_post_recv,
	.post_send = phoenix_post_send,
	.query_device_ex = phoenix_query_device,
	.query_port = phoenix_query_port,
	.query_qp = phoenix_query_qp,
	.reg_mr = phoenix_reg_mr,
	.req_notify_cq = phoenix_notify_cq,
};

static struct verbs_context *
phoenix_alloc_context(struct ibv_device *device, int cmd_fd, void *private_data)
{
	struct phoenix_cmd_alloc_context_resp resp = {};
	struct ibv_get_context cmd = {};
	struct phoenix_context *ctx;
	struct verbs_context *context;

	ctx = verbs_init_and_alloc_context(device, cmd_fd, ctx, ibv_ctx,
					   RDMA_DRIVER_PHOENIX);
	if (!ctx)
		return NULL;
	context = &ctx->ibv_ctx;

	verbs_err(context, "phoenix_alloc_context\n");

	if (ibv_cmd_get_context(context, &cmd, sizeof(cmd),
				&resp.ibv_resp, sizeof(resp)))
		goto err_out;

	verbs_err(context, "calling verbs_set_ops\n");

	verbs_set_ops(context, &phoenix_context_ops);

	return context;

err_out:
	verbs_err(context, "ibv_cmd_get_context failed\n");
	verbs_uninit_context(context);
	free(ctx);

	return NULL;
}

static struct verbs_device *
phoenix_device_alloc(struct verbs_sysfs_dev *sysfs_dev)
{
	struct phoenix_device *dev;
	dev = calloc(1, sizeof(*dev));
	if (!dev)
		return NULL;
	return &dev->ibv_dev;
}

static void phoenix_device_free(struct verbs_device *vdev)
{
	struct phoenix_device *dev =
		container_of(vdev, struct phoenix_device, ibv_dev);
	free(dev);
}

static const struct verbs_match_ent phoenix_table[] = {
	VERBS_DRIVER_ID(RDMA_DRIVER_PHOENIX),
	{},
};

static const struct verbs_device_ops phoenix_dev_ops = {
	.name = "phx",
	.match_min_abi_version = 0,
	.match_max_abi_version = PHOENIX_ABI_VERSION,
	.match_table = phoenix_table,
	.alloc_device = phoenix_device_alloc,
	.uninit_device = phoenix_device_free,
	.alloc_context = phoenix_alloc_context,
};

PROVIDER_DRIVER(phoenix, phoenix_dev_ops);