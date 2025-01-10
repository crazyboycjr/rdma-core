#ifndef __PHOENIX_H__
#define __PHOENIX_H__

#include <infiniband/driver.h>
#include <infiniband/kern-abi.h>

struct phoenix_device {
	struct verbs_device ibv_dev;
};

struct phoenix_context {
	struct verbs_context ibv_ctx;
};

static inline struct phoenix_context *to_phoenix_context(struct ibv_context *base) {
	return container_of(base, struct phoenix_context, ibv_ctx.context);
}

#endif /* __PHOENIX_H__ */