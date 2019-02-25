/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __DDP_PATH_H__
#define __DDP_PATH_H__

#include "ddp_info.h"
#include "cmdq_record.h"

typedef enum {
	DDP_VIDEO_MODE = 0,
	DDP_CMD_MODE,
} DDP_MODE;

typedef enum {
	DDP_SCENARIO_PRIMARY_DISP = 0,
	DDP_SCENARIO_PRIMARY_RDMA0_COLOR0_DISP,
	DDP_SCENARIO_PRIMARY_RDMA0_DISP,
	DDP_SCENARIO_PRIMARY_BYPASS_RDMA,
	DDP_SCENARIO_PRIMARY_OVL_MEMOUT,
	DDP_SCENARIO_PRIMARY_DITHER_MEMOUT,
	DDP_SCENARIO_PRIMARY_UFOE_MEMOUT,
	DDP_SCENARIO_SUB_DISP,
	DDP_SCENARIO_SUB_RDMA1_DISP,
	DDP_SCENARIO_SUB_OVL_MEMOUT,
	DDP_SCENARIO_PRIMARY_ALL,
	DDP_SCENARIO_SUB_ALL,
	DDP_SCENARIO_DITHER_1TO2,
	DDP_SCENARIO_UFOE_1TO2,
	DDP_SCENARIO_MAX
} DDP_SCENARIO_ENUM;

void ddp_connect_path(DDP_SCENARIO_ENUM scenario, void *handle);
void ddp_disconnect_path(DDP_SCENARIO_ENUM scenario, void *handle);
int ddp_get_module_num(DDP_SCENARIO_ENUM scenario);

void ddp_check_path(DDP_SCENARIO_ENUM scenario);
int ddp_mutex_set(int mutex_id, DDP_SCENARIO_ENUM scenario, DDP_MODE mode, void *handle);
int ddp_mutex_clear(int mutex_id, void *handle);
int ddp_mutex_enable(int mutex_id, DDP_SCENARIO_ENUM scenario, void *handle);
int ddp_mutex_disable(int mutex_id, DDP_SCENARIO_ENUM scenario, void *handle);
int ddp_mutex_get(int mutex_id, void *handle);
int ddp_mutex_release(int mutex_id, void *handle);

void ddp_check_mutex(int mutex_id, DDP_SCENARIO_ENUM scenario, DDP_MODE mode);
int ddp_mutex_reset(int mutex_id, void *handle);
int ddp_mutex_set_sof_wait(int mutex_id, cmdqRecHandle handle, int wait);

int ddp_is_moudule_in_mutex(int mutex_id, DISP_MODULE_ENUM module);

int ddp_mutex_add_module(int mutex_id, DISP_MODULE_ENUM module, void *handle);

int ddp_mutex_remove_module(int mutex_id, DISP_MODULE_ENUM module, void *handle);

int ddp_mutex_Interrupt_enable(int mutex_id, void *handle);

int ddp_mutex_Interrupt_disable(int mutex_id, void *handle);


DISP_MODULE_ENUM ddp_get_dst_module(DDP_SCENARIO_ENUM scenario);
int ddp_set_dst_module(DDP_SCENARIO_ENUM scenario, DISP_MODULE_ENUM dst_module);

int *ddp_get_scenario_list(DDP_SCENARIO_ENUM ddp_scenario);

int ddp_insert_module(DDP_SCENARIO_ENUM ddp_scenario, DISP_MODULE_ENUM place,
		      DISP_MODULE_ENUM module);
int ddp_remove_module(DDP_SCENARIO_ENUM ddp_scenario, DISP_MODULE_ENUM module);

int ddp_is_scenario_on_primary(DDP_SCENARIO_ENUM scenario);

char *ddp_get_scenario_name(DDP_SCENARIO_ENUM scenario);

int ddp_path_top_clock_off(void);
int ddp_path_top_clock_on(void);

/* should remove */
int ddp_insert_config_allow_rec(void *handle);
int ddp_insert_config_dirty_rec(void *handle);

int disp_get_dst_module(DDP_SCENARIO_ENUM scenario);
int ddp_is_module_in_scenario(DDP_SCENARIO_ENUM ddp_scenario, DISP_MODULE_ENUM module);
char *ddp_get_mutex_sof_name(unsigned int regval);
int ddp_path_init(void);
int ddp_convert_ovl_input_to_rdma(RDMA_CONFIG_STRUCT *rdma_cfg, OVL_CONFIG_STRUCT *ovl_cfg,
					int dst_w, int dst_h);
#endif
