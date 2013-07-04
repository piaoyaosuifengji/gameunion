//! IYY SDK 错误代码表
/*! 接口说明
* @file dw-api-error-codes.h
* @create date 2011-11-30
* @modify data 2011-11-30
* @author simon.lv
* @version 1.0
* @modify list
* ............................................................................
* ............................................................................
* yy open platform client api, 基于异步的yyplaitform 网络通信协议
* 广州华多网络科技有限公司 版权所有 (c) 2005-2011 DuoWan.com [多玩游戏]

******************************************************************************
* 详细接口文档参考open.yy.com
*******************************************************************************/

#ifndef _DW_PLATFORM_API_ERROR_CODES_H_
#define _DW_PLATFORM_API_ERROR_CODES_H_

const int yy_success = 0;

const int yy_e_unknown = 0x0001;
const int yy_e_buffer_length_is_out_of_limit = 0x0002;
const int yy_e_user_not_found = 0x0003;
const int yy_e_channel_not_found = 0x0004;

const int yy_e_cloud_add_data_failed = 0x0005;
const int yy_e_cloud_quary_data_failed = 0x0006;
const int yy_e_cloud_wrong_format = 0x0007;
const int yy_e_empty_msg = 0x0008;
const int yy_e_empty_user_list = 0x0009;
const int yy_e_user_count_out_of_limit = 0x000a;

const int yy_api_result_success = 0;

const int yy_api_register_api_failed_already_register = 0x000f0002;
const int yy_api_register_api_failed_time_out = 0x000f0003;
const int yy_api_register_api_failed_platform_not_exist = 0x000f0004;
const int yy_api_register_api_failed_platform_max_connect = 0x000f0005;
const int yy_api_register_api_failed_api_can_not_run = 0x000f0006;
const int yy_api_register_api_failed_api_sys_err	 = 0x000f0007;
const int yy_api_register_api_failed_platform_can_not_connected = 0x000f0008;

const int yy_api_release_failed_platform_exit = 0x000f0009;
const int yy_api_release_failed_yy_exit = 0x000f0010;

const int yy_api_transfer_data_failed_api_not_register_successed = 0x000f0011;
const int yy_api_transfer_data_failed_no_sender_state_error =  0x000f0012;
const int yy_api_transfer_ui_data_failed_api_not_register_successed = 0x000f0013;
const int yy_api_transfer_ui_data_failed_sender_state_error = 0x000f0014;
const int yy_api_get_channel_info_failed_api_not_register_successed = 0x000f0015;
const int yy_api_get_channel_info_failed_sender_state_error = 0x000f0016;
const int yy_api_get_user_info_failed_api_not_register_successed = 0x000f0017;
const int yy_api_get_user_info_failed_sender_state_error = 0x000f0018;

const int yy_api_get_user_name_failed_copy_str_err	= 0x000f0110;
const int yy_api_get_user_sign_failed_copy_str_err	= 0x000f0111;

const int yy_api_callback_aready_exist	= 0x000f0600;
const int yy_api_callback_not_exist		= 0x000f0601;
const int yy_api_route_sender_error		= 0x000f0602;
const int yy_api_callback_is_null		= 0x000f0603;

const int yy_api_block_waite_time_out   = 0x000f0700;
const int yy_api_block_watie_error      = 0x000f0701;
const int yy_api_block_terminal_is_null = 0x000f0702;
const int yy_api_asyn_call_error        = 0x000f0703;   

const int yy_api_not_connect_addon_server    = 0x000f0801;
const int yy_api_string_is_null              = 0x000f0802; //空字符串 
const int yy_api_buffer_is_too_small         = 0x000f0803;
const int yy_api_point_is_null               = 0x000f0804;
const int yy_api_contains_illegal_characters = 0x000f0805;

const int yy_api_call_interface_too_frequently = 0x000f0900;

#endif //_DW_PLATFORM_API_ERROR_CODES_H_