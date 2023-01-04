/*
 * SPDX-FileCopyrightText: 2022 Kyunghwan Kwon <k@mononn.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "pwifi/wifi.h"

struct wifi *dummy_wifi_create(void)
{
	return 0;
}

void dummy_wifi_destroy(struct wifi *inst)
{
	(void)inst;
}
