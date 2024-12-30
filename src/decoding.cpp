#include "../include/decoding.h" 
void decode_dura_max_eec5_electronic_engine_control_5(std::unordered_map<std::string, double>& value_map, dura_max_eec5_electronic_engine_control_5_t * strct )
{
	value_map["engine_turbocharger_1_calculated"] =  dura_max_eec5_electronic_engine_control_5_engine_turbocharger_1_calculated_decode(strct->engine_turbocharger_1_calculated);
	value_map["commanded_vgt_position"] =  dura_max_eec5_electronic_engine_control_5_commanded_vgt_position_decode(strct->commanded_vgt_position);
	value_map["engine_variable_geometry_turboch"] =  dura_max_eec5_electronic_engine_control_5_engine_variable_geometry_turboch_decode(strct->engine_variable_geometry_turboch);
	value_map["engine_fuel_control_control_mode"] =  dura_max_eec5_electronic_engine_control_5_engine_fuel_control_control_mode_decode(strct->engine_fuel_control_control_mode);
	value_map["engine_vgt_control_mode"] =  dura_max_eec5_electronic_engine_control_5_engine_vgt_control_mode_decode(strct->engine_vgt_control_mode);
	value_map["actual_vgt_position"] =  dura_max_eec5_electronic_engine_control_5_actual_vgt_position_decode(strct->actual_vgt_position);
}
void decode_dura_max_eec9_electronic_engine_control_9(std::unordered_map<std::string, double>& value_map, dura_max_eec9_electronic_engine_control_9_t * strct )
{
	value_map["engine_exhaust_gas_recirculation"] =  dura_max_eec9_electronic_engine_control_9_engine_exhaust_gas_recirculation_decode(strct->engine_exhaust_gas_recirculation);
	value_map["commanded_fuel_rail_pressure"] =  dura_max_eec9_electronic_engine_control_9_commanded_fuel_rail_pressure_decode(strct->commanded_fuel_rail_pressure);
	value_map["commanded_engine_fuel_injection_"] =  dura_max_eec9_electronic_engine_control_9_commanded_engine_fuel_injection__decode(strct->commanded_engine_fuel_injection_);
}
void decode_dura_max_ebcc_engine_exhaust_brake_cont(std::unordered_map<std::string, double>& value_map, dura_max_ebcc_engine_exhaust_brake_cont_t * strct )
{
	value_map["actual_boost_pressure"] =  dura_max_ebcc_engine_exhaust_brake_cont_actual_boost_pressure_decode(strct->actual_boost_pressure);
	value_map["desired_boost_pressure"] =  dura_max_ebcc_engine_exhaust_brake_cont_desired_boost_pressure_decode(strct->desired_boost_pressure);
	value_map["engine_exhaust_brake_actuator_co"] =  dura_max_ebcc_engine_exhaust_brake_cont_engine_exhaust_brake_actuator_co_decode(strct->engine_exhaust_brake_actuator_co);
	value_map["engine_turbocharger_2_turbine_ou"] =  dura_max_ebcc_engine_exhaust_brake_cont_engine_turbocharger_2_turbine_ou_decode(strct->engine_turbocharger_2_turbine_ou);
	value_map["desired_engine_turbocharger_2_tu"] =  dura_max_ebcc_engine_exhaust_brake_cont_desired_engine_turbocharger_2_tu_decode(strct->desired_engine_turbocharger_2_tu);
}
void decode_dura_max_et3_engine_temperature_3(std::unordered_map<std::string, double>& value_map, dura_max_et3_engine_temperature_3_t * strct )
{
	value_map["engine_intake_manifold_1_air_tem"] =  dura_max_et3_engine_temperature_3_engine_intake_manifold_1_air_tem_decode(strct->engine_intake_manifold_1_air_tem);
	value_map["engine_coolant_temperature_high"] =  dura_max_et3_engine_temperature_3_engine_coolant_temperature_high_decode(strct->engine_coolant_temperature_high);
	value_map["engine_intake_valve_actuation_sy"] =  dura_max_et3_engine_temperature_3_engine_intake_valve_actuation_sy_decode(strct->engine_intake_valve_actuation_sy);
	value_map["engine_cac_outlet_temperature"] =  dura_max_et3_engine_temperature_3_engine_cac_outlet_temperature_decode(strct->engine_cac_outlet_temperature);
}
void decode_dura_max_dm21_diagnostic_readiness_2(std::unordered_map<std::string, double>& value_map, dura_max_dm21_diagnostic_readiness_2_t * strct )
{
	value_map["engine_run_time_with_mil_on"] =  dura_max_dm21_diagnostic_readiness_2_engine_run_time_with_mil_on_decode(strct->engine_run_time_with_mil_on);
}
void decode_dura_max_dm26_diagnostic_readiness_3(std::unordered_map<std::string, double>& value_map, dura_max_dm26_diagnostic_readiness_3_t * strct )
{
	value_map["time_since_engine_start"] =  dura_max_dm26_diagnostic_readiness_3_time_since_engine_start_decode(strct->time_since_engine_start);
}
void decode_dura_max_ic1_intake_exhaust_cond_1(std::unordered_map<std::string, double>& value_map, dura_max_ic1_intake_exhaust_cond_1_t * strct )
{
	value_map["aft1_dpf_in_press"] =  dura_max_ic1_intake_exhaust_cond_1_aft1_dpf_in_press_decode(strct->aft1_dpf_in_press);
	value_map["eng_intake_manifold1_press"] =  dura_max_ic1_intake_exhaust_cond_1_eng_intake_manifold1_press_decode(strct->eng_intake_manifold1_press);
	value_map["eng_intake_manifold1_temp"] =  dura_max_ic1_intake_exhaust_cond_1_eng_intake_manifold1_temp_decode(strct->eng_intake_manifold1_temp);
	value_map["eng_air_intake_press"] =  dura_max_ic1_intake_exhaust_cond_1_eng_air_intake_press_decode(strct->eng_air_intake_press);
	value_map["eng_air_filter1_diff_press"] =  dura_max_ic1_intake_exhaust_cond_1_eng_air_filter1_diff_press_decode(strct->eng_air_filter1_diff_press);
	value_map["eng_exhaust_gas_temp"] =  dura_max_ic1_intake_exhaust_cond_1_eng_exhaust_gas_temp_decode(strct->eng_exhaust_gas_temp);
	value_map["eng_coolant_filter_diff_press"] =  dura_max_ic1_intake_exhaust_cond_1_eng_coolant_filter_diff_press_decode(strct->eng_coolant_filter_diff_press);
}
void decode_dura_max_amb_ambient_conditions(std::unordered_map<std::string, double>& value_map, dura_max_amb_ambient_conditions_t * strct )
{
	value_map["barometric_pressure_barometric_pr"] =  dura_max_amb_ambient_conditions_barometric_pressure_barometric_pr_decode(strct->barometric_pressure_barometric_pr);
	value_map["cab_interior_temp"] =  dura_max_amb_ambient_conditions_cab_interior_temp_decode(strct->cab_interior_temp);
	value_map["ambient_air_temperature"] =  dura_max_amb_ambient_conditions_ambient_air_temperature_decode(strct->ambient_air_temperature);
	value_map["engine_air_intake_temperature"] =  dura_max_amb_ambient_conditions_engine_air_intake_temperature_decode(strct->engine_air_intake_temperature);
	value_map["road_surface_temp"] =  dura_max_amb_ambient_conditions_road_surface_temp_decode(strct->road_surface_temp);
}
void decode_dura_max_eec1_electronic_engine_control_1(std::unordered_map<std::string, double>& value_map, dura_max_eec1_electronic_engine_control_1_t * strct )
{
	value_map["engine_torque_mode"] =  dura_max_eec1_electronic_engine_control_1_engine_torque_mode_decode(strct->engine_torque_mode);
	value_map["actl_eng_prcnt_torque_high_resolution"] =  dura_max_eec1_electronic_engine_control_1_actl_eng_prcnt_torque_high_resolution_decode(strct->actl_eng_prcnt_torque_high_resolution);
	value_map["drivers_demand_engine_prcnt_torq"] =  dura_max_eec1_electronic_engine_control_1_drivers_demand_engine_prcnt_torq_decode(strct->drivers_demand_engine_prcnt_torq);
	value_map["actual_engine_percent_torque"] =  dura_max_eec1_electronic_engine_control_1_actual_engine_percent_torque_decode(strct->actual_engine_percent_torque);
	value_map["engine_speed"] =  dura_max_eec1_electronic_engine_control_1_engine_speed_decode(strct->engine_speed);
	value_map["src_addrss_of_cntrllng_dvc_for_eng_ctrl"] =  dura_max_eec1_electronic_engine_control_1_src_addrss_of_cntrllng_dvc_for_eng_ctrl_decode(strct->src_addrss_of_cntrllng_dvc_for_eng_ctrl);
	value_map["eng_starter_mode"] =  dura_max_eec1_electronic_engine_control_1_eng_starter_mode_decode(strct->eng_starter_mode);
	value_map["engine_demand_percent_torque"] =  dura_max_eec1_electronic_engine_control_1_engine_demand_percent_torque_decode(strct->engine_demand_percent_torque);
}
void decode_dura_max_eec2_electronic_engine_control_2(std::unordered_map<std::string, double>& value_map, dura_max_eec2_electronic_engine_control_2_t * strct )
{
	value_map["accel_pedal1_low_idle_switch"] =  dura_max_eec2_electronic_engine_control_2_accel_pedal1_low_idle_switch_decode(strct->accel_pedal1_low_idle_switch);
	value_map["accel_pedal_kickdown_switch"] =  dura_max_eec2_electronic_engine_control_2_accel_pedal_kickdown_switch_decode(strct->accel_pedal_kickdown_switch);
	value_map["road_speed_limit_status"] =  dura_max_eec2_electronic_engine_control_2_road_speed_limit_status_decode(strct->road_speed_limit_status);
	value_map["accel_pedal2_low_idle_switch"] =  dura_max_eec2_electronic_engine_control_2_accel_pedal2_low_idle_switch_decode(strct->accel_pedal2_low_idle_switch);
	value_map["accel_pedal_pos1"] =  dura_max_eec2_electronic_engine_control_2_accel_pedal_pos1_decode(strct->accel_pedal_pos1);
	value_map["eng_percent_load_at_current_speed"] =  dura_max_eec2_electronic_engine_control_2_eng_percent_load_at_current_speed_decode(strct->eng_percent_load_at_current_speed);
	value_map["remote_accel_pedal_pos"] =  dura_max_eec2_electronic_engine_control_2_remote_accel_pedal_pos_decode(strct->remote_accel_pedal_pos);
	value_map["accel_pedal_pos2"] =  dura_max_eec2_electronic_engine_control_2_accel_pedal_pos2_decode(strct->accel_pedal_pos2);
	value_map["vhcle_acceleration_rate_limit_status"] =  dura_max_eec2_electronic_engine_control_2_vhcle_acceleration_rate_limit_status_decode(strct->vhcle_acceleration_rate_limit_status);
	value_map["mmntary_eng_max_power_enable_feedback"] =  dura_max_eec2_electronic_engine_control_2_mmntary_eng_max_power_enable_feedback_decode(strct->mmntary_eng_max_power_enable_feedback);
	value_map["dpf_thermal_management_active"] =  dura_max_eec2_electronic_engine_control_2_dpf_thermal_management_active_decode(strct->dpf_thermal_management_active);
	value_map["scr_thermal_management_active"] =  dura_max_eec2_electronic_engine_control_2_scr_thermal_management_active_decode(strct->scr_thermal_management_active);
	value_map["actl_max_available_eng_percent_torque"] =  dura_max_eec2_electronic_engine_control_2_actl_max_available_eng_percent_torque_decode(strct->actl_max_available_eng_percent_torque);
	value_map["est_pumping_percent_torque"] =  dura_max_eec2_electronic_engine_control_2_est_pumping_percent_torque_decode(strct->est_pumping_percent_torque);
}
void decode_dura_max_eec3_electronic_engine_control_3(std::unordered_map<std::string, double>& value_map, dura_max_eec3_electronic_engine_control_3_t * strct )
{
	value_map["nominal_friction_percent_torque"] =  dura_max_eec3_electronic_engine_control_3_nominal_friction_percent_torque_decode(strct->nominal_friction_percent_torque);
	value_map["engines_desired_operating_speed"] =  dura_max_eec3_electronic_engine_control_3_engines_desired_operating_speed_decode(strct->engines_desired_operating_speed);
	value_map["engns_dsrd_oprtng_spd_asymmtry_adjstm"] =  dura_max_eec3_electronic_engine_control_3_engns_dsrd_oprtng_spd_asymmtry_adjstm_decode(strct->engns_dsrd_oprtng_spd_asymmtry_adjstm);
	value_map["est_eng_prsitic_losses_percent_torque"] =  dura_max_eec3_electronic_engine_control_3_est_eng_prsitic_losses_percent_torque_decode(strct->est_eng_prsitic_losses_percent_torque);
	value_map["aft1_exh_gas_mfr"] =  dura_max_eec3_electronic_engine_control_3_aft1_exh_gas_mfr_decode(strct->aft1_exh_gas_mfr);
	value_map["aft1_in_dew_point"] =  dura_max_eec3_electronic_engine_control_3_aft1_in_dew_point_decode(strct->aft1_in_dew_point);
	value_map["aft1_exh_dew_point"] =  dura_max_eec3_electronic_engine_control_3_aft1_exh_dew_point_decode(strct->aft1_exh_dew_point);
	value_map["aft2_in_dew_point"] =  dura_max_eec3_electronic_engine_control_3_aft2_in_dew_point_decode(strct->aft2_in_dew_point);
	value_map["aft2_exh_dew_point"] =  dura_max_eec3_electronic_engine_control_3_aft2_exh_dew_point_decode(strct->aft2_exh_dew_point);
}
void decode_dura_max_efl_p1_eng_fluid_level_press_1(std::unordered_map<std::string, double>& value_map, dura_max_efl_p1_eng_fluid_level_press_1_t * strct )
{
	value_map["eng_fuel_delivery_press"] =  dura_max_efl_p1_eng_fluid_level_press_1_eng_fuel_delivery_press_decode(strct->eng_fuel_delivery_press);
	value_map["eng_ex_crankcase_blowby_press"] =  dura_max_efl_p1_eng_fluid_level_press_1_eng_ex_crankcase_blowby_press_decode(strct->eng_ex_crankcase_blowby_press);
	value_map["eng_oil_level"] =  dura_max_efl_p1_eng_fluid_level_press_1_eng_oil_level_decode(strct->eng_oil_level);
	value_map["eng_oil_press"] =  dura_max_efl_p1_eng_fluid_level_press_1_eng_oil_press_decode(strct->eng_oil_press);
	value_map["eng_crankcase_press"] =  dura_max_efl_p1_eng_fluid_level_press_1_eng_crankcase_press_decode(strct->eng_crankcase_press);
	value_map["eng_coolant_press"] =  dura_max_efl_p1_eng_fluid_level_press_1_eng_coolant_press_decode(strct->eng_coolant_press);
	value_map["eng_coolant_level"] =  dura_max_efl_p1_eng_fluid_level_press_1_eng_coolant_level_decode(strct->eng_coolant_level);
}
void decode_dura_max_efl_p2_eng_fluid_level_press_2(std::unordered_map<std::string, double>& value_map, dura_max_efl_p2_eng_fluid_level_press_2_t * strct )
{
	value_map["eng_injection_ctrl_press"] =  dura_max_efl_p2_eng_fluid_level_press_2_eng_injection_ctrl_press_decode(strct->eng_injection_ctrl_press);
	value_map["eng_injector_metering_rail1_press"] =  dura_max_efl_p2_eng_fluid_level_press_2_eng_injector_metering_rail1_press_decode(strct->eng_injector_metering_rail1_press);
	value_map["eng_injector_timing_rail1_press"] =  dura_max_efl_p2_eng_fluid_level_press_2_eng_injector_timing_rail1_press_decode(strct->eng_injector_timing_rail1_press);
	value_map["eng_injector_metering_rail2_press"] =  dura_max_efl_p2_eng_fluid_level_press_2_eng_injector_metering_rail2_press_decode(strct->eng_injector_metering_rail2_press);
}
void decode_dura_max_et1_engine_temperature_1(std::unordered_map<std::string, double>& value_map, dura_max_et1_engine_temperature_1_t * strct )
{
	value_map["eng_coolant_temp"] =  dura_max_et1_engine_temperature_1_eng_coolant_temp_decode(strct->eng_coolant_temp);
	value_map["eng_fuel_temp1"] =  dura_max_et1_engine_temperature_1_eng_fuel_temp1_decode(strct->eng_fuel_temp1);
	value_map["eng_oil_temp1"] =  dura_max_et1_engine_temperature_1_eng_oil_temp1_decode(strct->eng_oil_temp1);
	value_map["eng_turbo_oil_temp"] =  dura_max_et1_engine_temperature_1_eng_turbo_oil_temp_decode(strct->eng_turbo_oil_temp);
	value_map["eng_intercooler_temp"] =  dura_max_et1_engine_temperature_1_eng_intercooler_temp_decode(strct->eng_intercooler_temp);
	value_map["eng_intercooler_thermostat_opening"] =  dura_max_et1_engine_temperature_1_eng_intercooler_thermostat_opening_decode(strct->eng_intercooler_thermostat_opening);
}
void decode_dura_max_lfe1_fuel_economy_liquid_1(std::unordered_map<std::string, double>& value_map, dura_max_lfe1_fuel_economy_liquid_1_t * strct )
{
	value_map["eng_fuel_rate"] =  dura_max_lfe1_fuel_economy_liquid_1_eng_fuel_rate_decode(strct->eng_fuel_rate);
	value_map["eng_instantaneous_fuel_economy"] =  dura_max_lfe1_fuel_economy_liquid_1_eng_instantaneous_fuel_economy_decode(strct->eng_instantaneous_fuel_economy);
	value_map["eng_average_fuel_economy"] =  dura_max_lfe1_fuel_economy_liquid_1_eng_average_fuel_economy_decode(strct->eng_average_fuel_economy);
	value_map["eng_throttle_valve1_pos"] =  dura_max_lfe1_fuel_economy_liquid_1_eng_throttle_valve1_pos_decode(strct->eng_throttle_valve1_pos);
	value_map["eng_throttle_valve2_pos"] =  dura_max_lfe1_fuel_economy_liquid_1_eng_throttle_valve2_pos_decode(strct->eng_throttle_valve2_pos);
}
void decode_dura_max_transport_protocol_header(std::unordered_map<std::string, double>& value_map, dura_max_transport_protocol_header_t * strct )
{
	value_map["control_byte"] =  dura_max_transport_protocol_header_control_byte_decode(strct->control_byte);
	value_map["total_message_size_eo_ma"] =  dura_max_transport_protocol_header_total_message_size_eo_ma_decode(strct->total_message_size_eo_ma);
	value_map["connection_abort_reason"] =  dura_max_transport_protocol_header_connection_abort_reason_decode(strct->connection_abort_reason);
	value_map["total_message_size"] =  dura_max_transport_protocol_header_total_message_size_decode(strct->total_message_size);
	value_map["number_of_packets_that_can_be_sent"] =  dura_max_transport_protocol_header_number_of_packets_that_can_be_sent_decode(strct->number_of_packets_that_can_be_sent);
	value_map["total_message_size_bam"] =  dura_max_transport_protocol_header_total_message_size_bam_decode(strct->total_message_size_bam);
	value_map["next_packet_number_to_be_sent"] =  dura_max_transport_protocol_header_next_packet_number_to_be_sent_decode(strct->next_packet_number_to_be_sent);
	value_map["total_number_of_packets"] =  dura_max_transport_protocol_header_total_number_of_packets_decode(strct->total_number_of_packets);
	value_map["total_number_of_packets_eo_ma"] =  dura_max_transport_protocol_header_total_number_of_packets_eo_ma_decode(strct->total_number_of_packets_eo_ma);
	value_map["total_number_of_packets_bam"] =  dura_max_transport_protocol_header_total_number_of_packets_bam_decode(strct->total_number_of_packets_bam);
	value_map["maximum_number_of_packets"] =  dura_max_transport_protocol_header_maximum_number_of_packets_decode(strct->maximum_number_of_packets);
	value_map["pg_number"] =  dura_max_transport_protocol_header_pg_number_decode(strct->pg_number);
}
void decode_dura_max_transport_protocol_data(std::unordered_map<std::string, double>& value_map, dura_max_transport_protocol_data_t * strct )
{
	value_map["sequence_number"] =  dura_max_transport_protocol_data_sequence_number_decode(strct->sequence_number);
}
void decode_dura_max_dm01_active_diagnostics(std::unordered_map<std::string, double>& value_map, dura_max_dm01_active_diagnostics_t * strct )
{
	value_map["protect_lamp_status"] =  dura_max_dm01_active_diagnostics_protect_lamp_status_decode(strct->protect_lamp_status);
	value_map["amber_warning_lamp_status"] =  dura_max_dm01_active_diagnostics_amber_warning_lamp_status_decode(strct->amber_warning_lamp_status);
	value_map["red_stop_lamp_state"] =  dura_max_dm01_active_diagnostics_red_stop_lamp_state_decode(strct->red_stop_lamp_state);
	value_map["malfunction_indicator_lamp_status"] =  dura_max_dm01_active_diagnostics_malfunction_indicator_lamp_status_decode(strct->malfunction_indicator_lamp_status);
	value_map["flash_protect_lamp"] =  dura_max_dm01_active_diagnostics_flash_protect_lamp_decode(strct->flash_protect_lamp);
	value_map["flash_amber_warning_lamp"] =  dura_max_dm01_active_diagnostics_flash_amber_warning_lamp_decode(strct->flash_amber_warning_lamp);
	value_map["flash_red_stop_lamp"] =  dura_max_dm01_active_diagnostics_flash_red_stop_lamp_decode(strct->flash_red_stop_lamp);
	value_map["flash_malfunc_indicator_lamp"] =  dura_max_dm01_active_diagnostics_flash_malfunc_indicator_lamp_decode(strct->flash_malfunc_indicator_lamp);
	value_map["dtc1"] =  dura_max_dm01_active_diagnostics_dtc1_decode(strct->dtc1);
}
void decode_dura_max_tsc1_31(std::unordered_map<std::string, double>& value_map, dura_max_tsc1_31_t * strct )
{
	value_map["eng_override_ctrl_mode"] =  dura_max_tsc1_31_eng_override_ctrl_mode_decode(strct->eng_override_ctrl_mode);
	value_map["eng_requested_speed_ctrl_conditions"] =  dura_max_tsc1_31_eng_requested_speed_ctrl_conditions_decode(strct->eng_requested_speed_ctrl_conditions);
	value_map["override_ctrl_mode_priority"] =  dura_max_tsc1_31_override_ctrl_mode_priority_decode(strct->override_ctrl_mode_priority);
	value_map["eng_requested_speed_speed_limit"] =  dura_max_tsc1_31_eng_requested_speed_speed_limit_decode(strct->eng_requested_speed_speed_limit);
	value_map["eng_requested_torque_torque_limit"] =  dura_max_tsc1_31_eng_requested_torque_torque_limit_decode(strct->eng_requested_torque_torque_limit);
	value_map["tsc1_trans_rate"] =  dura_max_tsc1_31_tsc1_trans_rate_decode(strct->tsc1_trans_rate);
	value_map["tsc1_ctrl_purpose"] =  dura_max_tsc1_31_tsc1_ctrl_purpose_decode(strct->tsc1_ctrl_purpose);
	value_map["eng_requested_torque_high_resolution"] =  dura_max_tsc1_31_eng_requested_torque_high_resolution_decode(strct->eng_requested_torque_high_resolution);
	value_map["message_counter"] =  dura_max_tsc1_31_message_counter_decode(strct->message_counter);
	value_map["message_checksum"] =  dura_max_tsc1_31_message_checksum_decode(strct->message_checksum);
}
void decode_dura_max_cac1_charge_air_cooler_1(std::unordered_map<std::string, double>& value_map, dura_max_cac1_charge_air_cooler_1_t * strct )
{
	value_map["engine_charge_air_cooler_1_intak"] =  dura_max_cac1_charge_air_cooler_1_engine_charge_air_cooler_1_intak_decode(strct->engine_charge_air_cooler_1_intak);
	value_map["engine_charge_air_cooler_1_ambie"] =  dura_max_cac1_charge_air_cooler_1_engine_charge_air_cooler_1_ambie_decode(strct->engine_charge_air_cooler_1_ambie);
	value_map["engine_charge_air_cooler_1_effic"] =  dura_max_cac1_charge_air_cooler_1_engine_charge_air_cooler_1_effic_decode(strct->engine_charge_air_cooler_1_effic);
}
void decode_dura_max_hours_engine_hours_revolutions(std::unordered_map<std::string, double>& value_map, dura_max_hours_engine_hours_revolutions_t * strct )
{
	value_map["engine_total_hours_of_operation_"] =  dura_max_hours_engine_hours_revolutions_engine_total_hours_of_operation__decode(strct->engine_total_hours_of_operation_);
	value_map["engine_total_revolutions_249_"] =  dura_max_hours_engine_hours_revolutions_engine_total_revolutions_249__decode(strct->engine_total_revolutions_249_);
}
void decode_dura_max_tci5_turbocharger_information_5(std::unordered_map<std::string, double>& value_map, dura_max_tci5_turbocharger_information_5_t * strct )
{
	value_map["engine_turbocharger_1_turbine_ou"] =  dura_max_tci5_turbocharger_information_5_engine_turbocharger_1_turbine_ou_decode(strct->engine_turbocharger_1_turbine_ou);
	value_map["engine_turbocharger_2_turbine_ou"] =  dura_max_tci5_turbocharger_information_5_engine_turbocharger_2_turbine_ou_decode(strct->engine_turbocharger_2_turbine_ou);
	value_map["engine_turbocharger_3_turbine_ou"] =  dura_max_tci5_turbocharger_information_5_engine_turbocharger_3_turbine_ou_decode(strct->engine_turbocharger_3_turbine_ou);
	value_map["engine_turbocharger_4_turbine_ou"] =  dura_max_tci5_turbocharger_information_5_engine_turbocharger_4_turbine_ou_decode(strct->engine_turbocharger_4_turbine_ou);
}
void decode_dura_max_vep1_vehicle_electrical_power_1(std::unordered_map<std::string, double>& value_map, dura_max_vep1_vehicle_electrical_power_1_t * strct )
{
	value_map["net_battery_current_114_"] =  dura_max_vep1_vehicle_electrical_power_1_net_battery_current_114__decode(strct->net_battery_current_114_);
	value_map["alternator_current_115_"] =  dura_max_vep1_vehicle_electrical_power_1_alternator_current_115__decode(strct->alternator_current_115_);
	value_map["charging_system_potential_volta"] =  dura_max_vep1_vehicle_electrical_power_1_charging_system_potential_volta_decode(strct->charging_system_potential_volta);
	value_map["battery_potential_power_input_1_"] =  dura_max_vep1_vehicle_electrical_power_1_battery_potential_power_input_1__decode(strct->battery_potential_power_input_1_);
	value_map["keyswitch_battery_potential_158"] =  dura_max_vep1_vehicle_electrical_power_1_keyswitch_battery_potential_158_decode(strct->keyswitch_battery_potential_158);
}
void decode_dura_max_eec20_electronic_engine_control_(std::unordered_map<std::string, double>& value_map, dura_max_eec20_electronic_engine_control__t * strct )
{
	value_map["absolute_engine_load"] =  dura_max_eec20_electronic_engine_control__absolute_engine_load_decode(strct->absolute_engine_load);
}
void decode_dura_max_easi_engine_air_system_info(std::unordered_map<std::string, double>& value_map, dura_max_easi_engine_air_system_info_t * strct )
{
	value_map["engine_intake_maf"] =  dura_max_easi_engine_air_system_info_engine_intake_maf_decode(strct->engine_intake_maf);
}
void decode_dura_max_tsc1_03(std::unordered_map<std::string, double>& value_map, dura_max_tsc1_03_t * strct )
{
	value_map["eng_override_ctrl_mode"] =  dura_max_tsc1_03_eng_override_ctrl_mode_decode(strct->eng_override_ctrl_mode);
	value_map["eng_requested_speed_ctrl_conditions"] =  dura_max_tsc1_03_eng_requested_speed_ctrl_conditions_decode(strct->eng_requested_speed_ctrl_conditions);
	value_map["override_ctrl_mode_priority"] =  dura_max_tsc1_03_override_ctrl_mode_priority_decode(strct->override_ctrl_mode_priority);
	value_map["eng_requested_speed_speed_limit"] =  dura_max_tsc1_03_eng_requested_speed_speed_limit_decode(strct->eng_requested_speed_speed_limit);
	value_map["eng_requested_torque_torque_limit"] =  dura_max_tsc1_03_eng_requested_torque_torque_limit_decode(strct->eng_requested_torque_torque_limit);
	value_map["tsc1_trans_rate"] =  dura_max_tsc1_03_tsc1_trans_rate_decode(strct->tsc1_trans_rate);
	value_map["tsc1_ctrl_purpose"] =  dura_max_tsc1_03_tsc1_ctrl_purpose_decode(strct->tsc1_ctrl_purpose);
	value_map["eng_requested_torque_high_resolution"] =  dura_max_tsc1_03_eng_requested_torque_high_resolution_decode(strct->eng_requested_torque_high_resolution);
	value_map["message_counter"] =  dura_max_tsc1_03_message_counter_decode(strct->message_counter);
	value_map["message_checksum"] =  dura_max_tsc1_03_message_checksum_decode(strct->message_checksum);
}
void decode_dura_max_tsc1_0_b(std::unordered_map<std::string, double>& value_map, dura_max_tsc1_0_b_t * strct )
{
	value_map["eng_override_ctrl_mode"] =  dura_max_tsc1_0_b_eng_override_ctrl_mode_decode(strct->eng_override_ctrl_mode);
	value_map["eng_requested_speed_ctrl_conditions"] =  dura_max_tsc1_0_b_eng_requested_speed_ctrl_conditions_decode(strct->eng_requested_speed_ctrl_conditions);
	value_map["override_ctrl_mode_priority"] =  dura_max_tsc1_0_b_override_ctrl_mode_priority_decode(strct->override_ctrl_mode_priority);
	value_map["eng_requested_speed_speed_limit"] =  dura_max_tsc1_0_b_eng_requested_speed_speed_limit_decode(strct->eng_requested_speed_speed_limit);
	value_map["eng_requested_torque_torque_limit"] =  dura_max_tsc1_0_b_eng_requested_torque_torque_limit_decode(strct->eng_requested_torque_torque_limit);
	value_map["tsc1_trans_rate"] =  dura_max_tsc1_0_b_tsc1_trans_rate_decode(strct->tsc1_trans_rate);
	value_map["tsc1_ctrl_purpose"] =  dura_max_tsc1_0_b_tsc1_ctrl_purpose_decode(strct->tsc1_ctrl_purpose);
	value_map["eng_requested_torque_high_resolution"] =  dura_max_tsc1_0_b_eng_requested_torque_high_resolution_decode(strct->eng_requested_torque_high_resolution);
	value_map["message_counter"] =  dura_max_tsc1_0_b_message_counter_decode(strct->message_counter);
	value_map["message_checksum"] =  dura_max_tsc1_0_b_message_checksum_decode(strct->message_checksum);
}
void decode_dura_max_dm07(std::unordered_map<std::string, double>& value_map, dura_max_dm07_t * strct )
{
	value_map["test_identifier"] =  dura_max_dm07_test_identifier_decode(strct->test_identifier);
	value_map["spn1"] =  dura_max_dm07_spn1_decode(strct->spn1);
	value_map["failure_mode_identifier1"] =  dura_max_dm07_failure_mode_identifier1_decode(strct->failure_mode_identifier1);
	value_map["spn1_high"] =  dura_max_dm07_spn1_high_decode(strct->spn1_high);
}
void decode_dura_max_dm08(std::unordered_map<std::string, double>& value_map, dura_max_dm08_t * strct )
{
	value_map["test_identifier"] =  dura_max_dm08_test_identifier_decode(strct->test_identifier);
	value_map["test_type"] =  dura_max_dm08_test_type_decode(strct->test_type);
	value_map["test_value"] =  dura_max_dm08_test_value_decode(strct->test_value);
	value_map["test_limit_maximum"] =  dura_max_dm08_test_limit_maximum_decode(strct->test_limit_maximum);
	value_map["test_limit_minimum"] =  dura_max_dm08_test_limit_minimum_decode(strct->test_limit_minimum);
}
void decode_dura_max_erc1_electronic_retarder_cntrl(std::unordered_map<std::string, double>& value_map, dura_max_erc1_electronic_retarder_cntrl_t * strct )
{
	value_map["retarder_torque_mode"] =  dura_max_erc1_electronic_retarder_cntrl_retarder_torque_mode_decode(strct->retarder_torque_mode);
	value_map["retarder_enable_brake_assist_switch"] =  dura_max_erc1_electronic_retarder_cntrl_retarder_enable_brake_assist_switch_decode(strct->retarder_enable_brake_assist_switch);
	value_map["retarder_enable_shift_assist_switch"] =  dura_max_erc1_electronic_retarder_cntrl_retarder_enable_shift_assist_switch_decode(strct->retarder_enable_shift_assist_switch);
	value_map["actual_retarder_percent_torque"] =  dura_max_erc1_electronic_retarder_cntrl_actual_retarder_percent_torque_decode(strct->actual_retarder_percent_torque);
	value_map["intended_retarder_percent_torque"] =  dura_max_erc1_electronic_retarder_cntrl_intended_retarder_percent_torque_decode(strct->intended_retarder_percent_torque);
	value_map["eng_coolant_load_increase"] =  dura_max_erc1_electronic_retarder_cntrl_eng_coolant_load_increase_decode(strct->eng_coolant_load_increase);
	value_map["retarder_requesting_brake_light"] =  dura_max_erc1_electronic_retarder_cntrl_retarder_requesting_brake_light_decode(strct->retarder_requesting_brake_light);
	value_map["retarder_road_speed_limit_switch"] =  dura_max_erc1_electronic_retarder_cntrl_retarder_road_speed_limit_switch_decode(strct->retarder_road_speed_limit_switch);
	value_map["retarder_road_speed_exceeded_status"] =  dura_max_erc1_electronic_retarder_cntrl_retarder_road_speed_exceeded_status_decode(strct->retarder_road_speed_exceeded_status);
	value_map["src_addrss_of_cntrllng_dvc_fr_rtrdr_ctr"] =  dura_max_erc1_electronic_retarder_cntrl_src_addrss_of_cntrllng_dvc_fr_rtrdr_ctr_decode(strct->src_addrss_of_cntrllng_dvc_fr_rtrdr_ctr);
	value_map["drvrs_demand_retarder_percent_torque"] =  dura_max_erc1_electronic_retarder_cntrl_drvrs_demand_retarder_percent_torque_decode(strct->drvrs_demand_retarder_percent_torque);
	value_map["retarder_selection_nonengine"] =  dura_max_erc1_electronic_retarder_cntrl_retarder_selection_nonengine_decode(strct->retarder_selection_nonengine);
	value_map["actl_mx_avlbl_retarder_percent_torque"] =  dura_max_erc1_electronic_retarder_cntrl_actl_mx_avlbl_retarder_percent_torque_decode(strct->actl_mx_avlbl_retarder_percent_torque);
}
void decode_dura_max_etc1_electronic_trans_cntrl_1(std::unordered_map<std::string, double>& value_map, dura_max_etc1_electronic_trans_cntrl_1_t * strct )
{
	value_map["trans_driveline_engaged"] =  dura_max_etc1_electronic_trans_cntrl_1_trans_driveline_engaged_decode(strct->trans_driveline_engaged);
	value_map["trns_torque_converter_lockup_engaged"] =  dura_max_etc1_electronic_trans_cntrl_1_trns_torque_converter_lockup_engaged_decode(strct->trns_torque_converter_lockup_engaged);
	value_map["trans_shift_in_process"] =  dura_max_etc1_electronic_trans_cntrl_1_trans_shift_in_process_decode(strct->trans_shift_in_process);
	value_map["trns_trq_cnvrtr_lckp_trnstn_in_process"] =  dura_max_etc1_electronic_trans_cntrl_1_trns_trq_cnvrtr_lckp_trnstn_in_process_decode(strct->trns_trq_cnvrtr_lckp_trnstn_in_process);
	value_map["trans_output_shaft_speed"] =  dura_max_etc1_electronic_trans_cntrl_1_trans_output_shaft_speed_decode(strct->trans_output_shaft_speed);
	value_map["percent_clutch_slip"] =  dura_max_etc1_electronic_trans_cntrl_1_percent_clutch_slip_decode(strct->percent_clutch_slip);
	value_map["eng_momentary_overspeed_enable"] =  dura_max_etc1_electronic_trans_cntrl_1_eng_momentary_overspeed_enable_decode(strct->eng_momentary_overspeed_enable);
	value_map["progressive_shift_disable"] =  dura_max_etc1_electronic_trans_cntrl_1_progressive_shift_disable_decode(strct->progressive_shift_disable);
	value_map["momentary_eng_max_power_enable"] =  dura_max_etc1_electronic_trans_cntrl_1_momentary_eng_max_power_enable_decode(strct->momentary_eng_max_power_enable);
	value_map["trans_input_shaft_speed"] =  dura_max_etc1_electronic_trans_cntrl_1_trans_input_shaft_speed_decode(strct->trans_input_shaft_speed);
	value_map["src_addrss_of_cntrllng_dvc_fr_trns_ctrl"] =  dura_max_etc1_electronic_trans_cntrl_1_src_addrss_of_cntrllng_dvc_fr_trns_ctrl_decode(strct->src_addrss_of_cntrllng_dvc_fr_trns_ctrl);
}
void decode_dura_max_etc2_electronic_trans_cntrl_2(std::unordered_map<std::string, double>& value_map, dura_max_etc2_electronic_trans_cntrl_2_t * strct )
{
	value_map["trans_selected_gear"] =  dura_max_etc2_electronic_trans_cntrl_2_trans_selected_gear_decode(strct->trans_selected_gear);
	value_map["trans_actual_gear_ratio"] =  dura_max_etc2_electronic_trans_cntrl_2_trans_actual_gear_ratio_decode(strct->trans_actual_gear_ratio);
	value_map["trans_current_gear"] =  dura_max_etc2_electronic_trans_cntrl_2_trans_current_gear_decode(strct->trans_current_gear);
	value_map["trans_requested_range"] =  dura_max_etc2_electronic_trans_cntrl_2_trans_requested_range_decode(strct->trans_requested_range);
	value_map["trans_current_range"] =  dura_max_etc2_electronic_trans_cntrl_2_trans_current_range_decode(strct->trans_current_range);
}
void decode_dura_max_rqst_00_5_e(std::unordered_map<std::string, double>& value_map, dura_max_rqst_00_5_e_t * strct )
{
	value_map["parameter_group_number"] =  dura_max_rqst_00_5_e_parameter_group_number_decode(strct->parameter_group_number);
}
void decode_dura_max_rqst_00_21(std::unordered_map<std::string, double>& value_map, dura_max_rqst_00_21_t * strct )
{
	value_map["parameter_group_number"] =  dura_max_rqst_00_21_parameter_group_number_decode(strct->parameter_group_number);
}
void decode_dura_max_rqst_global_5_e(std::unordered_map<std::string, double>& value_map, dura_max_rqst_global_5_e_t * strct )
{
	value_map["parameter_group_number"] =  dura_max_rqst_global_5_e_parameter_group_number_decode(strct->parameter_group_number);
}
void decode_dura_max_rqst_global_03(std::unordered_map<std::string, double>& value_map, dura_max_rqst_global_03_t * strct )
{
	value_map["parameter_group_number"] =  dura_max_rqst_global_03_parameter_group_number_decode(strct->parameter_group_number);
}
void decode_dura_max_tci_transfer_case_information(std::unordered_map<std::string, double>& value_map, dura_max_tci_transfer_case_information_t * strct )
{
	value_map["transfer_case_status"] =  dura_max_tci_transfer_case_information_transfer_case_status_decode(strct->transfer_case_status);
	value_map["dir_status"] =  dura_max_tci_transfer_case_information_dir_status_decode(strct->dir_status);
	value_map["actual_gear_ratio"] =  dura_max_tci_transfer_case_information_actual_gear_ratio_decode(strct->actual_gear_ratio);
	value_map["message_counter"] =  dura_max_tci_transfer_case_information_message_counter_decode(strct->message_counter);
	value_map["message_checksum"] =  dura_max_tci_transfer_case_information_message_checksum_decode(strct->message_checksum);
}
void decode_dura_max_trf1_transmission_fluids_1(std::unordered_map<std::string, double>& value_map, dura_max_trf1_transmission_fluids_1_t * strct )
{
	value_map["clutch_press"] =  dura_max_trf1_transmission_fluids_1_clutch_press_decode(strct->clutch_press);
	value_map["trans_oil_level1"] =  dura_max_trf1_transmission_fluids_1_trans_oil_level1_decode(strct->trans_oil_level1);
	value_map["trans_filter_diff_press"] =  dura_max_trf1_transmission_fluids_1_trans_filter_diff_press_decode(strct->trans_filter_diff_press);
	value_map["trans_oil_press"] =  dura_max_trf1_transmission_fluids_1_trans_oil_press_decode(strct->trans_oil_press);
	value_map["trans_oil_temp1"] =  dura_max_trf1_transmission_fluids_1_trans_oil_temp1_decode(strct->trans_oil_temp1);
	value_map["trans_oil_level1_high_low"] =  dura_max_trf1_transmission_fluids_1_trans_oil_level1_high_low_decode(strct->trans_oil_level1_high_low);
	value_map["trans_oil_level1_countdown_timer"] =  dura_max_trf1_transmission_fluids_1_trans_oil_level1_countdown_timer_decode(strct->trans_oil_level1_countdown_timer);
	value_map["trans_oil_level1_measurement_status"] =  dura_max_trf1_transmission_fluids_1_trans_oil_level1_measurement_status_decode(strct->trans_oil_level1_measurement_status);
}
void decode_dura_max_ccss_cruise_control_vehicle_spd(std::unordered_map<std::string, double>& value_map, dura_max_ccss_cruise_control_vehicle_spd_t * strct )
{
	value_map["max_vehicle_speed_limit"] =  dura_max_ccss_cruise_control_vehicle_spd_max_vehicle_speed_limit_decode(strct->max_vehicle_speed_limit);
	value_map["cruise_ctrl_high_set_limit_speed"] =  dura_max_ccss_cruise_control_vehicle_spd_cruise_ctrl_high_set_limit_speed_decode(strct->cruise_ctrl_high_set_limit_speed);
	value_map["cruise_ctrl_low_set_limit_speed"] =  dura_max_ccss_cruise_control_vehicle_spd_cruise_ctrl_low_set_limit_speed_decode(strct->cruise_ctrl_low_set_limit_speed);
	value_map["max_vehicle_speed_limit6808"] =  dura_max_ccss_cruise_control_vehicle_spd_max_vehicle_speed_limit6808_decode(strct->max_vehicle_speed_limit6808);
	value_map["ctrl_sys_low_set_lmt_spd"] =  dura_max_ccss_cruise_control_vehicle_spd_ctrl_sys_low_set_lmt_spd_decode(strct->ctrl_sys_low_set_lmt_spd);
	value_map["ctrl_dis_cmd_support"] =  dura_max_ccss_cruise_control_vehicle_spd_ctrl_dis_cmd_support_decode(strct->ctrl_dis_cmd_support);
	value_map["ctrl_resume_cmd_support"] =  dura_max_ccss_cruise_control_vehicle_spd_ctrl_resume_cmd_support_decode(strct->ctrl_resume_cmd_support);
	value_map["ctrl_pause_cmd_support"] =  dura_max_ccss_cruise_control_vehicle_spd_ctrl_pause_cmd_support_decode(strct->ctrl_pause_cmd_support);
	value_map["ctrl_set_cmd_support"] =  dura_max_ccss_cruise_control_vehicle_spd_ctrl_set_cmd_support_decode(strct->ctrl_set_cmd_support);
	value_map["powertrain_adaptive_cc_type"] =  dura_max_ccss_cruise_control_vehicle_spd_powertrain_adaptive_cc_type_decode(strct->powertrain_adaptive_cc_type);
}
void decode_dura_max_ccvs1_cruise_control_veh_spd(std::unordered_map<std::string, double>& value_map, dura_max_ccvs1_cruise_control_veh_spd_t * strct )
{
	value_map["two_speed_axle_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_two_speed_axle_switch_decode(strct->two_speed_axle_switch);
	value_map["parking_brake_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_parking_brake_switch_decode(strct->parking_brake_switch);
	value_map["cruise_ctrl_pause_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_pause_switch_decode(strct->cruise_ctrl_pause_switch);
	value_map["park_brake_release_inhibit_rq"] =  dura_max_ccvs1_cruise_control_veh_spd_park_brake_release_inhibit_rq_decode(strct->park_brake_release_inhibit_rq);
	value_map["wheel_based_vehicle_speed"] =  dura_max_ccvs1_cruise_control_veh_spd_wheel_based_vehicle_speed_decode(strct->wheel_based_vehicle_speed);
	value_map["cruise_ctrl_active"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_active_decode(strct->cruise_ctrl_active);
	value_map["cruise_ctrl_enable_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_enable_switch_decode(strct->cruise_ctrl_enable_switch);
	value_map["brake_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_brake_switch_decode(strct->brake_switch);
	value_map["clutch_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_clutch_switch_decode(strct->clutch_switch);
	value_map["cruise_ctrl_set_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_set_switch_decode(strct->cruise_ctrl_set_switch);
	value_map["cruise_ctrl_coast_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_coast_switch_decode(strct->cruise_ctrl_coast_switch);
	value_map["cruise_ctrl_resume_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_resume_switch_decode(strct->cruise_ctrl_resume_switch);
	value_map["cruise_ctrl_accelerate_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_accelerate_switch_decode(strct->cruise_ctrl_accelerate_switch);
	value_map["cruise_ctrl_set_speed"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_set_speed_decode(strct->cruise_ctrl_set_speed);
	value_map["pto_governor_state"] =  dura_max_ccvs1_cruise_control_veh_spd_pto_governor_state_decode(strct->pto_governor_state);
	value_map["cruise_ctrl_states"] =  dura_max_ccvs1_cruise_control_veh_spd_cruise_ctrl_states_decode(strct->cruise_ctrl_states);
	value_map["eng_idle_increment_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_eng_idle_increment_switch_decode(strct->eng_idle_increment_switch);
	value_map["eng_idle_decrement_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_eng_idle_decrement_switch_decode(strct->eng_idle_decrement_switch);
	value_map["eng_test_mode_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_eng_test_mode_switch_decode(strct->eng_test_mode_switch);
	value_map["eng_shutdown_override_switch"] =  dura_max_ccvs1_cruise_control_veh_spd_eng_shutdown_override_switch_decode(strct->eng_shutdown_override_switch);
}
void decode_dura_max_ebc1_electronic_brake_cntrl(std::unordered_map<std::string, double>& value_map, dura_max_ebc1_electronic_brake_cntrl_t * strct )
{
	value_map["asr_eng_ctrl_active"] =  dura_max_ebc1_electronic_brake_cntrl_asr_eng_ctrl_active_decode(strct->asr_eng_ctrl_active);
	value_map["asr_brake_ctrl_active"] =  dura_max_ebc1_electronic_brake_cntrl_asr_brake_ctrl_active_decode(strct->asr_brake_ctrl_active);
	value_map["anti_lock_braking_active"] =  dura_max_ebc1_electronic_brake_cntrl_anti_lock_braking_active_decode(strct->anti_lock_braking_active);
	value_map["ebs_brake_switch"] =  dura_max_ebc1_electronic_brake_cntrl_ebs_brake_switch_decode(strct->ebs_brake_switch);
	value_map["brake_pedal_pos"] =  dura_max_ebc1_electronic_brake_cntrl_brake_pedal_pos_decode(strct->brake_pedal_pos);
	value_map["abs_offroad_switch"] =  dura_max_ebc1_electronic_brake_cntrl_abs_offroad_switch_decode(strct->abs_offroad_switch);
	value_map["asr_offroad_switch"] =  dura_max_ebc1_electronic_brake_cntrl_asr_offroad_switch_decode(strct->asr_offroad_switch);
	value_map["asr_hill_holder_switch"] =  dura_max_ebc1_electronic_brake_cntrl_asr_hill_holder_switch_decode(strct->asr_hill_holder_switch);
	value_map["traction_ctrl_override_switch"] =  dura_max_ebc1_electronic_brake_cntrl_traction_ctrl_override_switch_decode(strct->traction_ctrl_override_switch);
	value_map["accel_interlock_switch"] =  dura_max_ebc1_electronic_brake_cntrl_accel_interlock_switch_decode(strct->accel_interlock_switch);
	value_map["eng_derate_switch"] =  dura_max_ebc1_electronic_brake_cntrl_eng_derate_switch_decode(strct->eng_derate_switch);
	value_map["eng_aux_shutdown_switch"] =  dura_max_ebc1_electronic_brake_cntrl_eng_aux_shutdown_switch_decode(strct->eng_aux_shutdown_switch);
	value_map["remote_accel_enable_switch"] =  dura_max_ebc1_electronic_brake_cntrl_remote_accel_enable_switch_decode(strct->remote_accel_enable_switch);
	value_map["eng_retarder_selection"] =  dura_max_ebc1_electronic_brake_cntrl_eng_retarder_selection_decode(strct->eng_retarder_selection);
	value_map["abs_fully_operational"] =  dura_max_ebc1_electronic_brake_cntrl_abs_fully_operational_decode(strct->abs_fully_operational);
	value_map["ebs_red_warning_signal"] =  dura_max_ebc1_electronic_brake_cntrl_ebs_red_warning_signal_decode(strct->ebs_red_warning_signal);
	value_map["abs_ebs_amber_warning_signal"] =  dura_max_ebc1_electronic_brake_cntrl_abs_ebs_amber_warning_signal_decode(strct->abs_ebs_amber_warning_signal);
	value_map["atc_asr_information_signal"] =  dura_max_ebc1_electronic_brake_cntrl_atc_asr_information_signal_decode(strct->atc_asr_information_signal);
	value_map["src_addrss_of_cntrllng_dvc_fr_brke_ctrl"] =  dura_max_ebc1_electronic_brake_cntrl_src_addrss_of_cntrllng_dvc_fr_brke_ctrl_decode(strct->src_addrss_of_cntrllng_dvc_fr_brke_ctrl);
	value_map["railroad_mode_sw"] =  dura_max_ebc1_electronic_brake_cntrl_railroad_mode_sw_decode(strct->railroad_mode_sw);
	value_map["halt_brake_switch"] =  dura_max_ebc1_electronic_brake_cntrl_halt_brake_switch_decode(strct->halt_brake_switch);
	value_map["trailer_abs_status"] =  dura_max_ebc1_electronic_brake_cntrl_trailer_abs_status_decode(strct->trailer_abs_status);
	value_map["trctr_mntd_trailer_abs_warning_signal"] =  dura_max_ebc1_electronic_brake_cntrl_trctr_mntd_trailer_abs_warning_signal_decode(strct->trctr_mntd_trailer_abs_warning_signal);
}
void decode_dura_max_shutdn(std::unordered_map<std::string, double>& value_map, dura_max_shutdn_t * strct )
{
	value_map["eng_idle_shutdown_has_shutdown_eng"] =  dura_max_shutdn_eng_idle_shutdown_has_shutdown_eng_decode(strct->eng_idle_shutdown_has_shutdown_eng);
	value_map["eng_idle_shutdown_driver_alert_mode"] =  dura_max_shutdn_eng_idle_shutdown_driver_alert_mode_decode(strct->eng_idle_shutdown_driver_alert_mode);
	value_map["eng_idle_shutdown_timer_override"] =  dura_max_shutdn_eng_idle_shutdown_timer_override_decode(strct->eng_idle_shutdown_timer_override);
	value_map["eng_idle_shutdown_timer_state"] =  dura_max_shutdn_eng_idle_shutdown_timer_state_decode(strct->eng_idle_shutdown_timer_state);
	value_map["eng_idle_shutdown_timer_function"] =  dura_max_shutdn_eng_idle_shutdown_timer_function_decode(strct->eng_idle_shutdown_timer_function);
	value_map["a_c_high_press_fan_switch"] =  dura_max_shutdn_a_c_high_press_fan_switch_decode(strct->a_c_high_press_fan_switch);
	value_map["refrigerant_low_press_switch"] =  dura_max_shutdn_refrigerant_low_press_switch_decode(strct->refrigerant_low_press_switch);
	value_map["refrigerant_high_press_switch"] =  dura_max_shutdn_refrigerant_high_press_switch_decode(strct->refrigerant_high_press_switch);
	value_map["eng_wait_to_start_lamp"] =  dura_max_shutdn_eng_wait_to_start_lamp_decode(strct->eng_wait_to_start_lamp);
	value_map["eng_prtection_system_has_shutdown_eng"] =  dura_max_shutdn_eng_prtection_system_has_shutdown_eng_decode(strct->eng_prtection_system_has_shutdown_eng);
	value_map["eng_prtctn_systm_appraching_shutdown"] =  dura_max_shutdn_eng_prtctn_systm_appraching_shutdown_decode(strct->eng_prtctn_systm_appraching_shutdown);
	value_map["eng_protection_system_timer_override"] =  dura_max_shutdn_eng_protection_system_timer_override_decode(strct->eng_protection_system_timer_override);
	value_map["eng_protection_system_timer_state"] =  dura_max_shutdn_eng_protection_system_timer_state_decode(strct->eng_protection_system_timer_state);
	value_map["eng_protection_system_config"] =  dura_max_shutdn_eng_protection_system_config_decode(strct->eng_protection_system_config);
	value_map["eng_alarm_acknowledge"] =  dura_max_shutdn_eng_alarm_acknowledge_decode(strct->eng_alarm_acknowledge);
	value_map["eng_alarm_output_cmd_status"] =  dura_max_shutdn_eng_alarm_output_cmd_status_decode(strct->eng_alarm_output_cmd_status);
	value_map["eng_air_shutoff_cmd_status"] =  dura_max_shutdn_eng_air_shutoff_cmd_status_decode(strct->eng_air_shutoff_cmd_status);
	value_map["eng_overspeed_test"] =  dura_max_shutdn_eng_overspeed_test_decode(strct->eng_overspeed_test);
	value_map["eng_air_shutoff_status"] =  dura_max_shutdn_eng_air_shutoff_status_decode(strct->eng_air_shutoff_status);
	value_map["pto_shutdown_has_shutdown_eng"] =  dura_max_shutdn_pto_shutdown_has_shutdown_eng_decode(strct->pto_shutdown_has_shutdown_eng);
	value_map["clnt_lvl_eng_prtction_shutdown_status"] =  dura_max_shutdn_clnt_lvl_eng_prtction_shutdown_status_decode(strct->clnt_lvl_eng_prtction_shutdown_status);
	value_map["eng_oil_press_sw"] =  dura_max_shutdn_eng_oil_press_sw_decode(strct->eng_oil_press_sw);
}
