#include <mruby.h>
#include <string.h>
#include <assert.h>
#include <mruby/string.h>
#include <mruby/data.h>
#include <dragonruby.h>
#include "lib/pigpio/pigpio-bridge.c"

static drb_api_t *drb_api;

static void drb_free_foreign_object_indirect(mrb_state *state, void *pointer) {
    drb_api->drb_free_foreign_object(state, pointer);
}
static int drb_ffi__ZTSi_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSi_ToRuby(mrb_state *state, int value) {
    return mrb_fixnum_value(value);
}
static mrb_value drb_ffi_bridge_gpio_initialise_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bridge_gpio_initialise': wrong number of arguments (%d for 0)", argc);
    int ret_val = bridge_gpio_initialise();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bridge_gpio_terminate_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bridge_gpio_terminate': wrong number of arguments (%d for 0)", argc);
    int ret_val = bridge_gpio_terminate();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bridge_gpio_set_mode_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bridge_gpio_set_mode': wrong number of arguments (%d for 2)", argc);
    int gpio_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int mode_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = bridge_gpio_set_mode(gpio_0, mode_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bridge_gpio_set_pull_up_down_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bridge_gpio_set_pull_up_down': wrong number of arguments (%d for 2)", argc);
    int gpio_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int pud_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = bridge_gpio_set_pull_up_down(gpio_0, pud_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bridge_gpio_glitch_filter_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bridge_gpio_glitch_filter': wrong number of arguments (%d for 2)", argc);
    int gpio_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int steady_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = bridge_gpio_glitch_filter(gpio_0, steady_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bridge_gpio_read_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bridge_gpio_read': wrong number of arguments (%d for 1)", argc);
    int gpio_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = bridge_gpio_read(gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bridge_gpio_write_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bridge_gpio_write': wrong number of arguments (%d for 2)", argc);
    int gpio_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int value_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = bridge_gpio_write(gpio_0, value_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
DRB_FFI_EXPORT
void drb_register_c_extensions_with_api(mrb_state *state, struct drb_api_t *api) {
    drb_api = api;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_define_module_under(state, FFI, "C_PIGPIO");
    struct RClass *object_class = state->object_class;
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_initialise", drb_ffi_bridge_gpio_initialise_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_terminate", drb_ffi_bridge_gpio_terminate_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_set_mode", drb_ffi_bridge_gpio_set_mode_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_set_pull_up_down", drb_ffi_bridge_gpio_set_pull_up_down_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_glitch_filter", drb_ffi_bridge_gpio_glitch_filter_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_read", drb_ffi_bridge_gpio_read_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_write", drb_ffi_bridge_gpio_write_Binding, MRB_ARGS_REQ(2));
}
