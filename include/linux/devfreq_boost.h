// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2018-2019 Sultan Alsawaf <sultan@kerneltoast.com>.
 */
#ifndef _DEVFREQ_BOOST_H_
#define _DEVFREQ_BOOST_H_

#include <linux/devfreq.h>
#include <linux/types.h>

enum df_device {
	DEVFREQ_EXYNOS_MIF,
	DEVFREQ_MAX
};

#ifdef CONFIG_DEVFREQ_BOOST
void devfreq_boost_kick(enum df_device device);
void devfreq_boost_kick_max(enum df_device device, unsigned int duration_ms);
void devfreq_register_boost_device(enum df_device device, struct devfreq *df);
bool df_boost_within_input(unsigned long timeout_ms);
#else
static inline
void devfreq_boost_kick(enum df_device device)
{
}
static inline
void devfreq_boost_kick_max(enum df_device device, unsigned int duration_ms)
{
}
static inline
void devfreq_register_boost_device(enum df_device device, struct devfreq *df)
{
}
static inline bool df_boost_within_input(unsigned long timeout_ms)
{
	return true;
}
#endif

#endif /* _DEVFREQ_BOOST_H_ */
