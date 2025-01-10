#ifndef __PHOENIX_VERBS_H__
#define __PHOENIX_VERBS_H__

#include <inttypes.h>
#include <stddef.h>

#include <infiniband/driver.h>

struct ibv_pd *phoenix_alloc_pd(struct ibv_context *ctx);
int phoenix_free_pd(struct ibv_pd *pd);

int phoenix_query_device(struct ibv_context *ctx,
			 const struct ibv_query_device_ex_input *input,
			 struct ibv_device_attr_ex *attr, size_t attr_size);
int phoenix_query_port(struct ibv_context *ctx, uint8_t port,
		       struct ibv_port_attr *attr);

struct ibv_mr *phoenix_reg_mr(struct ibv_pd *pd, void *addr, size_t len,
			      uint64_t hca_va, int access);
int phoenix_dereg_mr(struct verbs_mr *vmr);

struct ibv_qp *phoenix_create_qp(struct ibv_pd *pd,
				 struct ibv_qp_init_attr *attr);
int phoenix_modify_qp(struct ibv_qp *base_qp, struct ibv_qp_attr *attr,
		      int attr_mask);
int phoenix_query_qp(struct ibv_qp *qp, struct ibv_qp_attr *attr, int attr_mask,
		     struct ibv_qp_init_attr *init_attr);
int phoenix_post_send(struct ibv_qp *base_qp, struct ibv_send_wr *wr,
		      struct ibv_send_wr **bad_wr);
int phoenix_post_recv(struct ibv_qp *base_qp, struct ibv_recv_wr *wr,
		      struct ibv_recv_wr **bad_wr);
int phoenix_destroy_qp(struct ibv_qp *base_qp);

void phoenix_free_context(struct ibv_context *ibv_ctx);

struct ibv_cq *phoenix_create_cq(struct ibv_context *ctx, int num_cqe,
				 struct ibv_comp_channel *channel,
				 int comp_vector);
int phoenix_destroy_cq(struct ibv_cq *base_cq);
int phoenix_notify_cq(struct ibv_cq *ibcq, int solicited);
void phoenix_cq_event(struct ibv_cq *ibcq);
int phoenix_poll_cq(struct ibv_cq *ibcq, int num_entries, struct ibv_wc *wc);

#endif /* __PHOENIX_VERBS_H__ */