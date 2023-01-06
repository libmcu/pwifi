/*
 * SPDX-FileCopyrightText: 2022 Kyunghwan Kwon <k@mononn.com>
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef PWIFI_INTERFACE_H
#define PWIFI_INTERFACE_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "pwifi/wifi.h"

#if !defined(CONCAT)
#define CONCAT_INTERNAL(a, b)	a ## b
#define CONCAT(a, b)		CONCAT_INTERNAL(a, b)
#endif

#undef esp32 /* to prevent expansion to a constant number since esp32 is defined by ESP-IDF build system */
#define wifi_create_default	CONCAT(TARGET_PLATFORM, _wifi_create)
#define wifi_destroy_default	CONCAT(TARGET_PLATFORM, _wifi_destroy)

struct wifi *wifi_create_default(void);
void wifi_destroy_default(struct wifi *inst);

static inline int wifi_connect(struct wifi *self,
			       const struct wifi_conn_param *param)
{
	return self->api.connect(self, param);
}

static inline int wifi_disconnect(struct wifi *self)
{
	return self->api.disconnect(self);
}

static inline int wifi_scan(struct wifi *self)
{
	return self->api.scan(self);
}

static inline int wifi_enable(struct wifi *self)
{
	return self->api.enable(self);
}

static inline int wifi_disable(struct wifi *self)
{
	return self->api.disable(self);
}

static inline int wifi_get_status(struct wifi *self,
				  struct wifi_iface_info *info)
{
	return self->api.get_status(self, info);
}

static inline int wifi_register_event_callback(struct wifi *self,
					       const wifi_event_callback_t cb)
{
	return self->api.register_event_callback(self, cb);
}

#if defined(__cplusplus)
}
#endif

#endif /* PWIFI_INTERFACE_H */
