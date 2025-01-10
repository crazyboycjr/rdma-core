#ifndef __PHOENIX_ABI_H__
#define __PHOENIX_ABI_H__

#include <infiniband/kern-abi.h>
#include <rdma/phx-abi.h>
#include <kernel-abi/phx-abi.h>

DECLARE_DRV_CMD(phoenix_cmd_alloc_context, IB_USER_VERBS_CMD_GET_CONTEXT, empty,
		phoenix_uresp_alloc_ctx);

#endif /* __PHOENIX_ABI_H__ */