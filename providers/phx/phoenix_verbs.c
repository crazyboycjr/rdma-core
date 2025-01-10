#include "phoenix_verbs.h"

struct ibv_pd *phoenix_alloc_pd(struct ibv_context *ctx)
{
	verbs_err(verbs_get_ctx(ctx), "phoenix_alloc_pd\n");
	return NULL;
}
int phoenix_free_pd(struct ibv_pd *pd)
{
	verbs_err(verbs_get_ctx(pd->context), "phoenix_free_pd\n");
	return NULL;
}

int phoenix_query_device(struct ibv_context *ctx,
			 const struct ibv_query_device_ex_input *input,
			 struct ibv_device_attr_ex *attr, size_t attr_size)
{
	verbs_err(verbs_get_ctx(ctx), "phoenix_query_device\n");
	return 0;
}
int phoenix_query_port(struct ibv_context *ctx, uint8_t port,
		       struct ibv_port_attr *attr)
{
	verbs_err(verbs_get_ctx(ctx), "phoenix_query_port\n");
	return 0;
}

struct ibv_mr *phoenix_reg_mr(struct ibv_pd *pd, void *addr, size_t len,
			      uint64_t hca_va, int access)
{
	verbs_err(verbs_get_ctx(pd->context), "phoenix_reg_mr\n");
	return NULL;
}
int phoenix_dereg_mr(struct verbs_mr *vmr)
{
	verbs_err(verbs_get_ctx(vmr->ibv_mr.pd->context), "phoenix_dereg_mr\n");
	return 0;
}

struct ibv_qp *phoenix_create_qp(struct ibv_pd *pd,
				 struct ibv_qp_init_attr *attr)
{
	verbs_err(verbs_get_ctx(pd->context), "phoenix_create_qp\n");
	return NULL;
}
int phoenix_modify_qp(struct ibv_qp *base_qp, struct ibv_qp_attr *attr,
		      int attr_mask)
{
	verbs_err(verbs_get_ctx(base_qp->context), "phoenix_modify_qp\n");
	return 0;
}
int phoenix_query_qp(struct ibv_qp *qp, struct ibv_qp_attr *attr, int attr_mask,
		     struct ibv_qp_init_attr *init_attr)
{
	verbs_err(verbs_get_ctx(qp->context), "phoenix_query_qp\n");
	return 0;
}
int phoenix_post_send(struct ibv_qp *base_qp, struct ibv_send_wr *wr,
		      struct ibv_send_wr **bad_wr)
{
	verbs_err(verbs_get_ctx(base_qp->context), "phoenix_post_send\n");
	return 0;
}
int phoenix_post_recv(struct ibv_qp *base_qp, struct ibv_recv_wr *wr,
		      struct ibv_recv_wr **bad_wr)
{
	verbs_err(verbs_get_ctx(base_qp->context), "phoenix_post_recv\n");
	return 0;
}
int phoenix_destroy_qp(struct ibv_qp *base_qp)
{
	verbs_err(verbs_get_ctx(base_qp->context), "phoenix_destroy_qp\n");
	return 0;
}

void phoenix_free_context(struct ibv_context *ibv_ctx)
{
	verbs_err(verbs_get_ctx(ibv_ctx), "phoenix_free_context\n");
}

struct ibv_cq *phoenix_create_cq(struct ibv_context *ctx, int num_cqe,
				 struct ibv_comp_channel *channel,
				 int comp_vector)
{
	verbs_err(verbs_get_ctx(ctx), "phoenix_create_cq\n");
	return NULL;
}
int phoenix_destroy_cq(struct ibv_cq *base_cq)
{
	verbs_err(verbs_get_ctx(base_cq->context), "phoenix_destroy_cq\n");
	return 0;
}
int phoenix_notify_cq(struct ibv_cq *ibcq, int solicited)
{
	verbs_err(verbs_get_ctx(ibcq->context), "phoenix_notify_cq\n");
	return 0;
}
void phoenix_cq_event(struct ibv_cq *ibcq)
{
	verbs_err(verbs_get_ctx(ibcq->context), "phoenix_cq_event\n");
}
int phoenix_poll_cq(struct ibv_cq *ibcq, int num_entries, struct ibv_wc *wc)
{
	verbs_err(verbs_get_ctx(ibcq->context), "phoenix_poll_cq\n");
	return 0;
}