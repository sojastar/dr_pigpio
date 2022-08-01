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
struct drb_foreign_object_ZTSPZ9nanosleepE8timespec {
    drb_foreign_object_kind kind;
    struct timespec *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPZ9nanosleepE8timespec = {"timespec*", drb_free_foreign_object_indirect};
static struct timespec *drb_ffi__ZTSPZ9nanosleepE8timespec_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "TimespecPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPZ9nanosleepE8timespec);
    return ((struct drb_foreign_object_ZTSPZ9nanosleepE8timespec *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPZ9nanosleepE8timespec_ToRuby(mrb_state *state, struct timespec *value) {
    struct drb_foreign_object_ZTSPZ9nanosleepE8timespec *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPZ9nanosleepE8timespec));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "TimespecPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPZ9nanosleepE8timespec);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPZ15clock_nanosleepE8timespec {
    drb_foreign_object_kind kind;
    struct timespec *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPZ15clock_nanosleepE8timespec = {"timespec*", drb_free_foreign_object_indirect};
static struct timespec *drb_ffi__ZTSPZ15clock_nanosleepE8timespec_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "TimespecPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPZ15clock_nanosleepE8timespec);
    return ((struct drb_foreign_object_ZTSPZ15clock_nanosleepE8timespec *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPZ15clock_nanosleepE8timespec_ToRuby(mrb_state *state, struct timespec *value) {
    struct drb_foreign_object_ZTSPZ15clock_nanosleepE8timespec *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPZ15clock_nanosleepE8timespec));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "TimespecPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPZ15clock_nanosleepE8timespec);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPv {
    drb_foreign_object_kind kind;
    void *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPv = {"void*", drb_free_foreign_object_indirect};
static void *drb_ffi__ZTSPv_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "VoidPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPv);
    return ((struct drb_foreign_object_ZTSPv *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPv_ToRuby(mrb_state *state, void *value) {
    struct drb_foreign_object_ZTSPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPv));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "VoidPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPv);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPPv {
    drb_foreign_object_kind kind;
    void **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPv = {"void**", drb_free_foreign_object_indirect};
static void **drb_ffi__ZTSPPv_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "VoidPointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPPv);
    return ((struct drb_foreign_object_ZTSPPv *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPv_ToRuby(mrb_state *state, void **value) {
    struct drb_foreign_object_ZTSPPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPv));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "VoidPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPPv);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPi {
    drb_foreign_object_kind kind;
    int *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPi = {"int*", drb_free_foreign_object_indirect};
static int *drb_ffi__ZTSPi_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "IntPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPi);
    return ((struct drb_foreign_object_ZTSPi *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPi_ToRuby(mrb_state *state, int *value) {
    struct drb_foreign_object_ZTSPi *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPi));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "IntPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPi);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP3$_0 {
    drb_foreign_object_kind kind;
    __pthread_unwind_buf_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP3$_0 = {"*", drb_free_foreign_object_indirect};
static __pthread_unwind_buf_t *drb_ffi__ZTSP3$_0_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP3$_0);
    return ((struct drb_foreign_object_ZTSP3$_0 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP3$_0_ToRuby(mrb_state *state, __pthread_unwind_buf_t *value) {
    struct drb_foreign_object_ZTSP3$_0 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_0));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP3$_0);
    return mrb_obj_value(rdata);
}
static unsigned int drb_ffi__ZTSj_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSj_ToRuby(mrb_state *state, unsigned int value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPFviiiE {
    drb_foreign_object_kind kind;
    void (*value)(int, int, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFviiiE = {"Function_0*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFviiiE_FromRuby(mrb_state *state, mrb_value self))(int, int, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_0Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFviiiE);
    return ((struct drb_foreign_object_ZTSPFviiiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFviiiE_ToRuby(mrb_state *state, void (*value)(int, int, int)) {
    struct drb_foreign_object_ZTSPFviiiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviiiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_0Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFviiiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFviiiPvE {
    drb_foreign_object_kind kind;
    void (*value)(int, int, int, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFviiiPvE = {"Function_1*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFviiiPvE_FromRuby(mrb_state *state, mrb_value self))(int, int, int, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_1Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFviiiPvE);
    return ((struct drb_foreign_object_ZTSPFviiiPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFviiiPvE_ToRuby(mrb_state *state, void (*value)(int, int, int, void *)) {
    struct drb_foreign_object_ZTSPFviiiPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviiiPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_1Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFviiiPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP3$_1 {
    drb_foreign_object_kind kind;
    gpioPulse_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP3$_1 = {"*", drb_free_foreign_object_indirect};
static gpioPulse_t *drb_ffi__ZTSP3$_1_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP3$_1);
    return ((struct drb_foreign_object_ZTSP3$_1 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP3$_1_ToRuby(mrb_state *state, gpioPulse_t *value) {
    struct drb_foreign_object_ZTSP3$_1 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_1));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP3$_1);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPc {
    drb_foreign_object_kind kind;
    char *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPc = {"char*", drb_free_foreign_object_indirect};
static char *drb_ffi__ZTSPc_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    if (mrb_type(self) == MRB_TT_STRING)
        return RSTRING_PTR(self);
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPc);
    return ((struct drb_foreign_object_ZTSPc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPc_ToRuby(mrb_state *state, char *value) {
    struct drb_foreign_object_ZTSPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPc);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP3$_2 {
    drb_foreign_object_kind kind;
    pi_i2c_msg_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP3$_2 = {"*", drb_free_foreign_object_indirect};
static pi_i2c_msg_t *drb_ffi__ZTSP3$_2_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP3$_2);
    return ((struct drb_foreign_object_ZTSP3$_2 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP3$_2_ToRuby(mrb_state *state, pi_i2c_msg_t *value) {
    struct drb_foreign_object_ZTSP3$_2 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_2));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP3$_2);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP3$_3 {
    drb_foreign_object_kind kind;
    bsc_xfer_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP3$_3 = {"*", drb_free_foreign_object_indirect};
static bsc_xfer_t *drb_ffi__ZTSP3$_3_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP3$_3);
    return ((struct drb_foreign_object_ZTSP3$_3 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP3$_3_ToRuby(mrb_state *state, bsc_xfer_t *value) {
    struct drb_foreign_object_ZTSP3$_3 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_3));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP3$_3);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPK3$_4iE {
    drb_foreign_object_kind kind;
    void (*value)(const gpioSample_t *, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPK3$_4iE = {"Function_2*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPK3$_4iE_FromRuby(mrb_state *state, mrb_value self))(const gpioSample_t *, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_2Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPK3$_4iE);
    return ((struct drb_foreign_object_ZTSPFvPK3$_4iE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iE_ToRuby(mrb_state *state, void (*value)(const gpioSample_t *, int)) {
    struct drb_foreign_object_ZTSPFvPK3$_4iE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPK3$_4iE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_2Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPK3$_4iE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPK3$_4iPvE {
    drb_foreign_object_kind kind;
    void (*value)(const gpioSample_t *, int, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPK3$_4iPvE = {"Function_3*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPK3$_4iPvE_FromRuby(mrb_state *state, mrb_value self))(const gpioSample_t *, int, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_3Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPK3$_4iPvE);
    return ((struct drb_foreign_object_ZTSPFvPK3$_4iPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iPvE_ToRuby(mrb_state *state, void (*value)(const gpioSample_t *, int, void *)) {
    struct drb_foreign_object_ZTSPFvPK3$_4iPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPK3$_4iPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_3Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPK3$_4iPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvvE {
    drb_foreign_object_kind kind;
    void (*value)(void);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvvE = {"Function_4*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvvE_FromRuby(mrb_state *state, mrb_value self))(void) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_4Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvvE);
    return ((struct drb_foreign_object_ZTSPFvvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvvE_ToRuby(mrb_state *state, void (*value)(void)) {
    struct drb_foreign_object_ZTSPFvvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_4Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPvE {
    drb_foreign_object_kind kind;
    void (*value)(void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPvE = {"Function_5*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPvE_FromRuby(mrb_state *state, mrb_value self))(void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_5Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPvE);
    return ((struct drb_foreign_object_ZTSPFvPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPvE_ToRuby(mrb_state *state, void (*value)(void *)) {
    struct drb_foreign_object_ZTSPFvPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_5Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFPvS_E {
    drb_foreign_object_kind kind;
    gpioThreadFunc_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFPvS_E = {"Function_6*", drb_free_foreign_object_indirect};
static gpioThreadFunc_t *drb_ffi__ZTSPFPvS_E_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_6Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFPvS_E);
    return ((struct drb_foreign_object_ZTSPFPvS_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFPvS_E_ToRuby(mrb_state *state, gpioThreadFunc_t *value) {
    struct drb_foreign_object_ZTSPFPvS_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPvS_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_6Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFPvS_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFviE {
    drb_foreign_object_kind kind;
    void (*value)(int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFviE = {"Function_7*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFviE_FromRuby(mrb_state *state, mrb_value self))(int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_7Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFviE);
    return ((struct drb_foreign_object_ZTSPFviE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFviE_ToRuby(mrb_state *state, void (*value)(int)) {
    struct drb_foreign_object_ZTSPFviE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_7Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFviE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFviPvE {
    drb_foreign_object_kind kind;
    void (*value)(int, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFviPvE = {"Function_8*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFviPvE_FromRuby(mrb_state *state, mrb_value self))(int, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_8Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFviPvE);
    return ((struct drb_foreign_object_ZTSPFviPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFviPvE_ToRuby(mrb_state *state, void (*value)(int, void *)) {
    struct drb_foreign_object_ZTSPFviPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_8Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFviPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFviiE {
    drb_foreign_object_kind kind;
    void (*value)(int, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFviiE = {"Function_9*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFviiE_FromRuby(mrb_state *state, mrb_value self))(int, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_9Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFviiE);
    return ((struct drb_foreign_object_ZTSPFviiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFviiE_ToRuby(mrb_state *state, void (*value)(int, int)) {
    struct drb_foreign_object_ZTSPFviiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_9Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFviiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFviiPvE {
    drb_foreign_object_kind kind;
    void (*value)(int, int, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFviiPvE = {"Function_10*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFviiPvE_FromRuby(mrb_state *state, mrb_value self))(int, int, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_10Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFviiPvE);
    return ((struct drb_foreign_object_ZTSPFviiPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFviiPvE_ToRuby(mrb_state *state, void (*value)(int, int, void *)) {
    struct drb_foreign_object_ZTSPFviiPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviiPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_10Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFviiPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP8rawSPI_t {
    drb_foreign_object_kind kind;
    rawSPI_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP8rawSPI_t = {"*", drb_free_foreign_object_indirect};
static rawSPI_t *drb_ffi__ZTSP8rawSPI_t_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP8rawSPI_t);
    return ((struct drb_foreign_object_ZTSP8rawSPI_t *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP8rawSPI_t_ToRuby(mrb_state *state, rawSPI_t *value) {
    struct drb_foreign_object_ZTSP8rawSPI_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP8rawSPI_t));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP8rawSPI_t);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP3$_5 {
    drb_foreign_object_kind kind;
    rawWave_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP3$_5 = {"*", drb_free_foreign_object_indirect};
static rawWave_t *drb_ffi__ZTSP3$_5_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP3$_5);
    return ((struct drb_foreign_object_ZTSP3$_5 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP3$_5_ToRuby(mrb_state *state, rawWave_t *value) {
    struct drb_foreign_object_ZTSP3$_5 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_5));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP3$_5);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP3$_6 {
    drb_foreign_object_kind kind;
    rawCbs_t *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP3$_6 = {"*", drb_free_foreign_object_indirect};
static rawCbs_t *drb_ffi__ZTSP3$_6_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP3$_6);
    return ((struct drb_foreign_object_ZTSP3$_6 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP3$_6_ToRuby(mrb_state *state, rawCbs_t *value) {
    struct drb_foreign_object_ZTSP3$_6 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_6));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP3$_6);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS3$_7 {
    drb_foreign_object_kind kind;
    rawWaveInfo_t value;
};
static mrb_data_type ForeignObjectType_ZTS3$_7 = {"", drb_free_foreign_object_indirect};
static rawWaveInfo_t drb_ffi__ZTS3$_7_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS3$_7);
    return ((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS3$_7_ToRuby(mrb_state *state, rawWaveInfo_t value) {
    struct drb_foreign_object_ZTS3$_7 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_7));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_7);
    return mrb_obj_value(rdata);
}
static double drb_ffi__ZTSd_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_float(state, self);
    return mrb_float(self);
}
static mrb_value drb_ffi__ZTSd_ToRuby(mrb_state *state, double value) {
    return drb_api->drb_float_value(state, value);
}
struct drb_foreign_object_ZTS3$_0 {
    drb_foreign_object_kind kind;
    __pthread_unwind_buf_t value;
};
static mrb_data_type ForeignObjectType_ZTS3$_0 = {"", drb_free_foreign_object_indirect};
static __pthread_unwind_buf_t drb_ffi__ZTS3$_0_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS3$_0);
    return ((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS3$_0_ToRuby(mrb_state *state, __pthread_unwind_buf_t value) {
    struct drb_foreign_object_ZTS3$_0 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_0));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_0);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS3$_1 {
    drb_foreign_object_kind kind;
    gpioPulse_t value;
};
static mrb_data_type ForeignObjectType_ZTS3$_1 = {"", drb_free_foreign_object_indirect};
static gpioPulse_t drb_ffi__ZTS3$_1_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS3$_1);
    return ((struct drb_foreign_object_ZTS3$_1 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS3$_1_ToRuby(mrb_state *state, gpioPulse_t value) {
    struct drb_foreign_object_ZTS3$_1 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_1));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_1);
    return mrb_obj_value(rdata);
}
static char drb_ffi__ZTSc_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSc_ToRuby(mrb_state *state, char value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTS3$_2 {
    drb_foreign_object_kind kind;
    pi_i2c_msg_t value;
};
static mrb_data_type ForeignObjectType_ZTS3$_2 = {"", drb_free_foreign_object_indirect};
static pi_i2c_msg_t drb_ffi__ZTS3$_2_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS3$_2);
    return ((struct drb_foreign_object_ZTS3$_2 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS3$_2_ToRuby(mrb_state *state, pi_i2c_msg_t value) {
    struct drb_foreign_object_ZTS3$_2 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_2));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_2);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS3$_3 {
    drb_foreign_object_kind kind;
    bsc_xfer_t value;
};
static mrb_data_type ForeignObjectType_ZTS3$_3 = {"", drb_free_foreign_object_indirect};
static bsc_xfer_t drb_ffi__ZTS3$_3_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS3$_3);
    return ((struct drb_foreign_object_ZTS3$_3 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS3$_3_ToRuby(mrb_state *state, bsc_xfer_t value) {
    struct drb_foreign_object_ZTS3$_3 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_3));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_3);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS8rawSPI_t {
    drb_foreign_object_kind kind;
    rawSPI_t value;
};
static mrb_data_type ForeignObjectType_ZTS8rawSPI_t = {"", drb_free_foreign_object_indirect};
static rawSPI_t drb_ffi__ZTS8rawSPI_t_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS8rawSPI_t);
    return ((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS8rawSPI_t_ToRuby(mrb_state *state, rawSPI_t value) {
    struct drb_foreign_object_ZTS8rawSPI_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS8rawSPI_t));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS8rawSPI_t);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS3$_5 {
    drb_foreign_object_kind kind;
    rawWave_t value;
};
static mrb_data_type ForeignObjectType_ZTS3$_5 = {"", drb_free_foreign_object_indirect};
static rawWave_t drb_ffi__ZTS3$_5_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS3$_5);
    return ((struct drb_foreign_object_ZTS3$_5 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS3$_5_ToRuby(mrb_state *state, rawWave_t value) {
    struct drb_foreign_object_ZTS3$_5 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_5));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_5);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS3$_6 {
    drb_foreign_object_kind kind;
    rawCbs_t value;
};
static mrb_data_type ForeignObjectType_ZTS3$_6 = {"", drb_free_foreign_object_indirect};
static rawCbs_t drb_ffi__ZTS3$_6_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS3$_6);
    return ((struct drb_foreign_object_ZTS3$_6 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS3$_6_ToRuby(mrb_state *state, rawCbs_t value) {
    struct drb_foreign_object_ZTS3$_6 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_6));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_6);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPZ9nanosleepE8timespec_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPZ9nanosleepE8timespec_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPZ9nanosleepE8timespec_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPZ9nanosleepE8timespec_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPZ9nanosleepE8timespec_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPZ9nanosleepE8timespec_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPZ15clock_nanosleepE8timespec_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPZ15clock_nanosleepE8timespec_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPZ15clock_nanosleepE8timespec_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPZ15clock_nanosleepE8timespec_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPZ15clock_nanosleepE8timespec_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPZ15clock_nanosleepE8timespec_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPPv_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPv));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "VoidPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPPv);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPv_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPv_ToRuby(mrb, *drb_ffi__ZTSPPv_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPv_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPv_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPv_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPv_ToRuby(mrb, drb_ffi__ZTSPPv_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPv_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    void *new_value = drb_ffi__ZTSPv_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPv_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPi_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPi *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPi));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "IntPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPi);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPi_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSi_ToRuby(mrb, *drb_ffi__ZTSPi_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPi_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPi_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPi_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSi_ToRuby(mrb, drb_ffi__ZTSPi_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPi_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    int new_value = drb_ffi__ZTSi_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPi_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP3$_0_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP3$_0 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_0));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(__pthread_unwind_buf_t));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP3$_0);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP3$_0_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS3$_0_ToRuby(mrb, *drb_ffi__ZTSP3$_0_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP3$_0_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP3$_0_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP3$_0_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS3$_0_ToRuby(mrb, drb_ffi__ZTSP3$_0_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP3$_0_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    __pthread_unwind_buf_t new_value = drb_ffi__ZTS3$_0_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP3$_0_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFviiiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviiiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (int, int, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_0Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFviiiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFviiiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFviiiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFviiiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiiPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFviiiPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviiiPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (int, int, int, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_1Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFviiiPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFviiiPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiiPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFviiiPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFviiiPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiiPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP3$_1_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP3$_1 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_1));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(gpioPulse_t));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP3$_1);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP3$_1_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS3$_1_ToRuby(mrb, *drb_ffi__ZTSP3$_1_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP3$_1_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP3$_1_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP3$_1_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS3$_1_ToRuby(mrb, drb_ffi__ZTSP3$_1_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP3$_1_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    gpioPulse_t new_value = drb_ffi__ZTS3$_1_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP3$_1_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPc_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPc));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(char));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "CharPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPc);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPc_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSc_ToRuby(mrb, *drb_ffi__ZTSPc_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPc_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPc_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPc_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSc_ToRuby(mrb, drb_ffi__ZTSPc_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPc_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    char new_value = drb_ffi__ZTSc_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPc_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPc_GetString(mrb_state *state, mrb_value self) {
    return drb_api->mrb_str_new_cstr(state, drb_ffi__ZTSPc_FromRuby(state, self));
}
static mrb_value drb_ffi__ZTSP3$_2_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP3$_2 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_2));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(pi_i2c_msg_t));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP3$_2);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP3$_2_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS3$_2_ToRuby(mrb, *drb_ffi__ZTSP3$_2_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP3$_2_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP3$_2_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP3$_2_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS3$_2_ToRuby(mrb, drb_ffi__ZTSP3$_2_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP3$_2_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    pi_i2c_msg_t new_value = drb_ffi__ZTS3$_2_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP3$_2_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP3$_3_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP3$_3 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_3));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(bsc_xfer_t));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP3$_3);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP3$_3_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS3$_3_ToRuby(mrb, *drb_ffi__ZTSP3$_3_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP3$_3_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP3$_3_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP3$_3_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS3$_3_ToRuby(mrb, drb_ffi__ZTSP3$_3_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP3$_3_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    bsc_xfer_t new_value = drb_ffi__ZTS3$_3_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP3$_3_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPK3$_4iE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPK3$_4iE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (const gpioSample_t *, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_2Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPK3$_4iE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPK3$_4iE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPK3$_4iPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPK3$_4iPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (const gpioSample_t *, int, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_3Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPK3$_4iPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPK3$_4iPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPK3$_4iPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_4Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_5Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvS_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFPvS_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPvS_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(gpioThreadFunc_t));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_6Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFPvS_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFPvS_E_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvS_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFPvS_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFPvS_E_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvS_E_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFviE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_7Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFviE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFviE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFviE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFviE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFviPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (int, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_8Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFviPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFviPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFviPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFviPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFviiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (int, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_9Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFviiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFviiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFviiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFviiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFviiPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFviiPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (int, int, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_10Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFviiPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFviiPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFviiPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFviiPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFviiPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP8rawSPI_t_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP8rawSPI_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP8rawSPI_t));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(rawSPI_t));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP8rawSPI_t);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP8rawSPI_t_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS8rawSPI_t_ToRuby(mrb, *drb_ffi__ZTSP8rawSPI_t_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP8rawSPI_t_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP8rawSPI_t_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP8rawSPI_t_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS8rawSPI_t_ToRuby(mrb, drb_ffi__ZTSP8rawSPI_t_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP8rawSPI_t_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    rawSPI_t new_value = drb_ffi__ZTS8rawSPI_t_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP8rawSPI_t_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP3$_5_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP3$_5 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_5));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(rawWave_t));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP3$_5);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP3$_5_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS3$_5_ToRuby(mrb, *drb_ffi__ZTSP3$_5_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP3$_5_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP3$_5_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP3$_5_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS3$_5_ToRuby(mrb, drb_ffi__ZTSP3$_5_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP3$_5_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    rawWave_t new_value = drb_ffi__ZTS3$_5_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP3$_5_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP3$_6_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP3$_6 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_6));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(rawCbs_t));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP3$_6);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP3$_6_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS3$_6_ToRuby(mrb, *drb_ffi__ZTSP3$_6_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP3$_6_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP3$_6_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP3$_6_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS3$_6_ToRuby(mrb, drb_ffi__ZTSP3$_6_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP3$_6_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    rawCbs_t new_value = drb_ffi__ZTS3$_6_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP3$_6_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_7_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS3$_7 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_7 *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_7);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS3$_7_botCB_Get(mrb_state *state, mrb_value self) {
    rawWaveInfo_t record = drb_ffi__ZTS3$_7_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.botCB);
}
static mrb_value drb_ffi__ZTS3$_7_botCB_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value)->botCB = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_7_topCB_Get(mrb_state *state, mrb_value self) {
    rawWaveInfo_t record = drb_ffi__ZTS3$_7_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.topCB);
}
static mrb_value drb_ffi__ZTS3$_7_topCB_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value)->topCB = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_7_botOOL_Get(mrb_state *state, mrb_value self) {
    rawWaveInfo_t record = drb_ffi__ZTS3$_7_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.botOOL);
}
static mrb_value drb_ffi__ZTS3$_7_botOOL_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value)->botOOL = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_7_topOOL_Get(mrb_state *state, mrb_value self) {
    rawWaveInfo_t record = drb_ffi__ZTS3$_7_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.topOOL);
}
static mrb_value drb_ffi__ZTS3$_7_topOOL_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value)->topOOL = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_7_deleted_Get(mrb_state *state, mrb_value self) {
    rawWaveInfo_t record = drb_ffi__ZTS3$_7_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.deleted);
}
static mrb_value drb_ffi__ZTS3$_7_deleted_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value)->deleted = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_7_numCB_Get(mrb_state *state, mrb_value self) {
    rawWaveInfo_t record = drb_ffi__ZTS3$_7_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.numCB);
}
static mrb_value drb_ffi__ZTS3$_7_numCB_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value)->numCB = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_7_numBOOL_Get(mrb_state *state, mrb_value self) {
    rawWaveInfo_t record = drb_ffi__ZTS3$_7_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.numBOOL);
}
static mrb_value drb_ffi__ZTS3$_7_numBOOL_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value)->numBOOL = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_7_numTOOL_Get(mrb_state *state, mrb_value self) {
    rawWaveInfo_t record = drb_ffi__ZTS3$_7_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.numTOOL);
}
static mrb_value drb_ffi__ZTS3$_7_numTOOL_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_7 *)DATA_PTR(self))->value)->numTOOL = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS3$_0 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_0 *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_0);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS3$_0___cancel_jmp_buf_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0___cancel_jmp_buf_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0___pad_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0___pad_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_1_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS3$_1 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_1 *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_1);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS3$_1_gpioOn_Get(mrb_state *state, mrb_value self) {
    gpioPulse_t record = drb_ffi__ZTS3$_1_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.gpioOn);
}
static mrb_value drb_ffi__ZTS3$_1_gpioOn_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_1 *)DATA_PTR(self))->value)->gpioOn = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_1_gpioOff_Get(mrb_state *state, mrb_value self) {
    gpioPulse_t record = drb_ffi__ZTS3$_1_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.gpioOff);
}
static mrb_value drb_ffi__ZTS3$_1_gpioOff_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_1 *)DATA_PTR(self))->value)->gpioOff = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_1_usDelay_Get(mrb_state *state, mrb_value self) {
    gpioPulse_t record = drb_ffi__ZTS3$_1_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.usDelay);
}
static mrb_value drb_ffi__ZTS3$_1_usDelay_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_1 *)DATA_PTR(self))->value)->usDelay = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_2_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS3$_2 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_2 *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_2);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS3$_2_addr_Get(mrb_state *state, mrb_value self) {
    pi_i2c_msg_t record = drb_ffi__ZTS3$_2_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.addr);
}
static mrb_value drb_ffi__ZTS3$_2_addr_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_2 *)DATA_PTR(self))->value)->addr = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_2_flags_Get(mrb_state *state, mrb_value self) {
    pi_i2c_msg_t record = drb_ffi__ZTS3$_2_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.flags);
}
static mrb_value drb_ffi__ZTS3$_2_flags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_2 *)DATA_PTR(self))->value)->flags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_2_len_Get(mrb_state *state, mrb_value self) {
    pi_i2c_msg_t record = drb_ffi__ZTS3$_2_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.len);
}
static mrb_value drb_ffi__ZTS3$_2_len_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_2 *)DATA_PTR(self))->value)->len = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_2_buf_Get(mrb_state *state, mrb_value self) {
    pi_i2c_msg_t record = drb_ffi__ZTS3$_2_FromRuby(state, self);
    return drb_ffi__ZTSPi_ToRuby(state, record.buf);
}
static mrb_value drb_ffi__ZTS3$_2_buf_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int *new_value = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_2 *)DATA_PTR(self))->value)->buf = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_3_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS3$_3 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_3 *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_3);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS3$_3_control_Get(mrb_state *state, mrb_value self) {
    bsc_xfer_t record = drb_ffi__ZTS3$_3_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.control);
}
static mrb_value drb_ffi__ZTS3$_3_control_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_3 *)DATA_PTR(self))->value)->control = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_3_rxCnt_Get(mrb_state *state, mrb_value self) {
    bsc_xfer_t record = drb_ffi__ZTS3$_3_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.rxCnt);
}
static mrb_value drb_ffi__ZTS3$_3_rxCnt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_3 *)DATA_PTR(self))->value)->rxCnt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_3_rxBuf_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_3_rxBuf_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_3_txCnt_Get(mrb_state *state, mrb_value self) {
    bsc_xfer_t record = drb_ffi__ZTS3$_3_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.txCnt);
}
static mrb_value drb_ffi__ZTS3$_3_txCnt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_3 *)DATA_PTR(self))->value)->txCnt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_3_txBuf_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_3_txBuf_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8rawSPI_t_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS8rawSPI_t *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS8rawSPI_t *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS8rawSPI_t);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_clk_Get(mrb_state *state, mrb_value self) {
    rawSPI_t record = drb_ffi__ZTS8rawSPI_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.clk);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_clk_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value)->clk = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8rawSPI_t_mosi_Get(mrb_state *state, mrb_value self) {
    rawSPI_t record = drb_ffi__ZTS8rawSPI_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.mosi);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_mosi_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value)->mosi = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8rawSPI_t_miso_Get(mrb_state *state, mrb_value self) {
    rawSPI_t record = drb_ffi__ZTS8rawSPI_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.miso);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_miso_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value)->miso = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8rawSPI_t_ss_pol_Get(mrb_state *state, mrb_value self) {
    rawSPI_t record = drb_ffi__ZTS8rawSPI_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.ss_pol);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_ss_pol_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value)->ss_pol = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8rawSPI_t_ss_us_Get(mrb_state *state, mrb_value self) {
    rawSPI_t record = drb_ffi__ZTS8rawSPI_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.ss_us);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_ss_us_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value)->ss_us = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8rawSPI_t_clk_pol_Get(mrb_state *state, mrb_value self) {
    rawSPI_t record = drb_ffi__ZTS8rawSPI_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.clk_pol);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_clk_pol_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value)->clk_pol = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8rawSPI_t_clk_pha_Get(mrb_state *state, mrb_value self) {
    rawSPI_t record = drb_ffi__ZTS8rawSPI_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.clk_pha);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_clk_pha_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value)->clk_pha = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8rawSPI_t_clk_us_Get(mrb_state *state, mrb_value self) {
    rawSPI_t record = drb_ffi__ZTS8rawSPI_t_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.clk_us);
}
static mrb_value drb_ffi__ZTS8rawSPI_t_clk_us_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8rawSPI_t *)DATA_PTR(self))->value)->clk_us = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_5_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS3$_5 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_5 *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_5);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS3$_5_gpioOn_Get(mrb_state *state, mrb_value self) {
    rawWave_t record = drb_ffi__ZTS3$_5_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.gpioOn);
}
static mrb_value drb_ffi__ZTS3$_5_gpioOn_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_5 *)DATA_PTR(self))->value)->gpioOn = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_5_gpioOff_Get(mrb_state *state, mrb_value self) {
    rawWave_t record = drb_ffi__ZTS3$_5_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.gpioOff);
}
static mrb_value drb_ffi__ZTS3$_5_gpioOff_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_5 *)DATA_PTR(self))->value)->gpioOff = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_5_usDelay_Get(mrb_state *state, mrb_value self) {
    rawWave_t record = drb_ffi__ZTS3$_5_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.usDelay);
}
static mrb_value drb_ffi__ZTS3$_5_usDelay_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_5 *)DATA_PTR(self))->value)->usDelay = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_5_flags_Get(mrb_state *state, mrb_value self) {
    rawWave_t record = drb_ffi__ZTS3$_5_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.flags);
}
static mrb_value drb_ffi__ZTS3$_5_flags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_5 *)DATA_PTR(self))->value)->flags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_6_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS3$_6 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_6 *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_6);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS3$_6_info_Get(mrb_state *state, mrb_value self) {
    rawCbs_t record = drb_ffi__ZTS3$_6_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.info);
}
static mrb_value drb_ffi__ZTS3$_6_info_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_6 *)DATA_PTR(self))->value)->info = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_6_src_Get(mrb_state *state, mrb_value self) {
    rawCbs_t record = drb_ffi__ZTS3$_6_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.src);
}
static mrb_value drb_ffi__ZTS3$_6_src_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_6 *)DATA_PTR(self))->value)->src = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_6_dst_Get(mrb_state *state, mrb_value self) {
    rawCbs_t record = drb_ffi__ZTS3$_6_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.dst);
}
static mrb_value drb_ffi__ZTS3$_6_dst_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_6 *)DATA_PTR(self))->value)->dst = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_6_length_Get(mrb_state *state, mrb_value self) {
    rawCbs_t record = drb_ffi__ZTS3$_6_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.length);
}
static mrb_value drb_ffi__ZTS3$_6_length_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_6 *)DATA_PTR(self))->value)->length = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_6_stride_Get(mrb_state *state, mrb_value self) {
    rawCbs_t record = drb_ffi__ZTS3$_6_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.stride);
}
static mrb_value drb_ffi__ZTS3$_6_stride_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_6 *)DATA_PTR(self))->value)->stride = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_6_next_Get(mrb_state *state, mrb_value self) {
    rawCbs_t record = drb_ffi__ZTS3$_6_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.next);
}
static mrb_value drb_ffi__ZTS3$_6_next_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_6 *)DATA_PTR(self))->value)->next = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_6_pad_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_6_pad_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi_nanosleep_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'nanosleep': wrong number of arguments (%d for 2)", argc);
    struct timespec *__requested_time_0 = drb_ffi__ZTSPZ9nanosleepE8timespec_FromRuby(state, args[0]);
    struct timespec *__remaining_1 = drb_ffi__ZTSPZ9nanosleepE8timespec_FromRuby(state, args[1]);
    int ret_val = nanosleep(__requested_time_0, __remaining_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_clock_nanosleep_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'clock_nanosleep': wrong number of arguments (%d for 4)", argc);
    int __clock_id_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int __flags_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    struct timespec *__req_2 = drb_ffi__ZTSPZ15clock_nanosleepE8timespec_FromRuby(state, args[2]);
    struct timespec *__rem_3 = drb_ffi__ZTSPZ15clock_nanosleepE8timespec_FromRuby(state, args[3]);
    int ret_val = clock_nanosleep(__clock_id_0, __flags_1, __req_2, __rem_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_pthread_exit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'pthread_exit': wrong number of arguments (%d for 1)", argc);
    void *__retval_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    pthread_exit(__retval_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_pthread_join_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'pthread_join': wrong number of arguments (%d for 2)", argc);
    int __th_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    void **__thread_return_1 = drb_ffi__ZTSPPv_FromRuby(state, args[1]);
    int ret_val = pthread_join(__th_0, __thread_return_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_pthread_setcancelstate_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'pthread_setcancelstate': wrong number of arguments (%d for 2)", argc);
    int __state_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *__oldstate_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = pthread_setcancelstate(__state_0, __oldstate_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_pthread_setcanceltype_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'pthread_setcanceltype': wrong number of arguments (%d for 2)", argc);
    int __type_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *__oldtype_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = pthread_setcanceltype(__type_0, __oldtype_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_pthread_cancel_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'pthread_cancel': wrong number of arguments (%d for 1)", argc);
    int __th_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = pthread_cancel(__th_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_pthread_testcancel_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'pthread_testcancel': wrong number of arguments (%d for 0)", argc);
    pthread_testcancel();
    return mrb_nil_value();
}
static mrb_value drb_ffi___pthread_register_cancel_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'__pthread_register_cancel': wrong number of arguments (%d for 1)", argc);
    __pthread_unwind_buf_t *__buf_0 = drb_ffi__ZTSP3$_0_FromRuby(state, args[0]);
    __pthread_register_cancel(__buf_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi___pthread_unregister_cancel_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'__pthread_unregister_cancel': wrong number of arguments (%d for 1)", argc);
    __pthread_unwind_buf_t *__buf_0 = drb_ffi__ZTSP3$_0_FromRuby(state, args[0]);
    __pthread_unregister_cancel(__buf_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi___pthread_unwind_next_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'__pthread_unwind_next': wrong number of arguments (%d for 1)", argc);
    __pthread_unwind_buf_t *__buf_0 = drb_ffi__ZTSP3$_0_FromRuby(state, args[0]);
    __pthread_unwind_next(__buf_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_gpioInitialise_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioInitialise': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioInitialise();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioTerminate_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioTerminate': wrong number of arguments (%d for 0)", argc);
    gpioTerminate();
    return mrb_nil_value();
}
static mrb_value drb_ffi_gpioSetMode_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetMode': wrong number of arguments (%d for 2)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int mode_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioSetMode(gpio_0, mode_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioGetMode_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioGetMode': wrong number of arguments (%d for 1)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioGetMode(gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetPullUpDown_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetPullUpDown': wrong number of arguments (%d for 2)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int pud_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioSetPullUpDown(gpio_0, pud_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioRead_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioRead': wrong number of arguments (%d for 1)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioRead(gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWrite_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWrite': wrong number of arguments (%d for 2)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int level_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioWrite(gpio_0, level_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioPWM_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioPWM': wrong number of arguments (%d for 2)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int dutycycle_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioPWM(user_gpio_0, dutycycle_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioGetPWMdutycycle_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioGetPWMdutycycle': wrong number of arguments (%d for 1)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioGetPWMdutycycle(user_gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetPWMrange_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetPWMrange': wrong number of arguments (%d for 2)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int range_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioSetPWMrange(user_gpio_0, range_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioGetPWMrange_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioGetPWMrange': wrong number of arguments (%d for 1)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioGetPWMrange(user_gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioGetPWMrealRange_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioGetPWMrealRange': wrong number of arguments (%d for 1)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioGetPWMrealRange(user_gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetPWMfrequency_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetPWMfrequency': wrong number of arguments (%d for 2)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int frequency_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioSetPWMfrequency(user_gpio_0, frequency_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioGetPWMfrequency_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioGetPWMfrequency': wrong number of arguments (%d for 1)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioGetPWMfrequency(user_gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioServo_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioServo': wrong number of arguments (%d for 2)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int pulsewidth_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioServo(user_gpio_0, pulsewidth_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioGetServoPulsewidth_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioGetServoPulsewidth': wrong number of arguments (%d for 1)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioGetServoPulsewidth(user_gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetAlertFunc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetAlertFunc': wrong number of arguments (%d for 2)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    void (*f_1)(int, int, int) = drb_ffi__ZTSPFviiiE_FromRuby(state, args[1]);
    int ret_val = gpioSetAlertFunc(user_gpio_0, f_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetAlertFuncEx_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetAlertFuncEx': wrong number of arguments (%d for 3)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    void (*f_1)(int, int, int, void *) = drb_ffi__ZTSPFviiiPvE_FromRuby(state, args[1]);
    void *userdata_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    int ret_val = gpioSetAlertFuncEx(user_gpio_0, f_1, userdata_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetISRFunc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetISRFunc': wrong number of arguments (%d for 4)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int edge_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int timeout_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void (*f_3)(int, int, int) = drb_ffi__ZTSPFviiiE_FromRuby(state, args[3]);
    int ret_val = gpioSetISRFunc(gpio_0, edge_1, timeout_2, f_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetISRFuncEx_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetISRFuncEx': wrong number of arguments (%d for 5)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int edge_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int timeout_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void (*f_3)(int, int, int, void *) = drb_ffi__ZTSPFviiiPvE_FromRuby(state, args[3]);
    void *userdata_4 = drb_ffi__ZTSPv_FromRuby(state, args[4]);
    int ret_val = gpioSetISRFuncEx(gpio_0, edge_1, timeout_2, f_3, userdata_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioNotifyOpen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioNotifyOpen': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioNotifyOpen();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioNotifyOpenWithSize_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioNotifyOpenWithSize': wrong number of arguments (%d for 1)", argc);
    int bufSize_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = gpioNotifyOpenWithSize(bufSize_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioNotifyBegin_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioNotifyBegin': wrong number of arguments (%d for 2)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int bits_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = gpioNotifyBegin(handle_0, bits_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioNotifyPause_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioNotifyPause': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioNotifyPause(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioNotifyClose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioNotifyClose': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioNotifyClose(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveClear_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveClear': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveClear();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveAddNew_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveAddNew': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveAddNew();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveAddGeneric_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveAddGeneric': wrong number of arguments (%d for 2)", argc);
    unsigned int numPulses_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    gpioPulse_t *pulses_1 = drb_ffi__ZTSP3$_1_FromRuby(state, args[1]);
    int ret_val = gpioWaveAddGeneric(numPulses_0, pulses_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveAddSerial_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 7)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveAddSerial': wrong number of arguments (%d for 7)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int baud_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int data_bits_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    unsigned int stop_bits_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    unsigned int offset_4 = drb_ffi__ZTSj_FromRuby(state, args[4]);
    unsigned int numBytes_5 = drb_ffi__ZTSj_FromRuby(state, args[5]);
    char *str_6 = drb_ffi__ZTSPc_FromRuby(state, args[6]);
    int ret_val = gpioWaveAddSerial(user_gpio_0, baud_1, data_bits_2, stop_bits_3, offset_4, numBytes_5, str_6);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveCreate_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveCreate': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveCreate();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveCreatePad_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveCreatePad': wrong number of arguments (%d for 3)", argc);
    int pctCB_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int pctBOOL_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int pctTOOL_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = gpioWaveCreatePad(pctCB_0, pctBOOL_1, pctTOOL_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveDelete_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveDelete': wrong number of arguments (%d for 1)", argc);
    unsigned int wave_id_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioWaveDelete(wave_id_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveTxSend_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveTxSend': wrong number of arguments (%d for 2)", argc);
    unsigned int wave_id_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int wave_mode_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioWaveTxSend(wave_id_0, wave_mode_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveChain_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveChain': wrong number of arguments (%d for 2)", argc);
    char *buf_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    unsigned int bufSize_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioWaveChain(buf_0, bufSize_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveTxAt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveTxAt': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveTxAt();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveTxBusy_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveTxBusy': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveTxBusy();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveTxStop_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveTxStop': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveTxStop();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetMicros_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetMicros': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetMicros();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetHighMicros_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetHighMicros': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetHighMicros();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetMaxMicros_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetMaxMicros': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetMaxMicros();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetPulses_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetPulses': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetPulses();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetHighPulses_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetHighPulses': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetHighPulses();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetMaxPulses_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetMaxPulses': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetMaxPulses();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetCbs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetCbs': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetCbs();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetHighCbs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetHighCbs': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetHighCbs();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWaveGetMaxCbs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWaveGetMaxCbs': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioWaveGetMaxCbs();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSerialReadOpen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSerialReadOpen': wrong number of arguments (%d for 3)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int baud_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int data_bits_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = gpioSerialReadOpen(user_gpio_0, baud_1, data_bits_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSerialReadInvert_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSerialReadInvert': wrong number of arguments (%d for 2)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int invert_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioSerialReadInvert(user_gpio_0, invert_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSerialRead_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSerialRead': wrong number of arguments (%d for 3)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    void *buf_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int bufSize_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = gpioSerialRead(user_gpio_0, buf_1, bufSize_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSerialReadClose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSerialReadClose': wrong number of arguments (%d for 1)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioSerialReadClose(user_gpio_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cOpen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cOpen': wrong number of arguments (%d for 3)", argc);
    unsigned int i2cBus_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cAddr_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int i2cFlags_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = i2cOpen(i2cBus_0, i2cAddr_1, i2cFlags_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cClose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cClose': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = i2cClose(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cWriteQuick_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cWriteQuick': wrong number of arguments (%d for 2)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int bit_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = i2cWriteQuick(handle_0, bit_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cWriteByte_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cWriteByte': wrong number of arguments (%d for 2)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int bVal_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = i2cWriteByte(handle_0, bVal_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cReadByte_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cReadByte': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = i2cReadByte(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cWriteByteData_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cWriteByteData': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int bVal_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = i2cWriteByteData(handle_0, i2cReg_1, bVal_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cWriteWordData_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cWriteWordData': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int wVal_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = i2cWriteWordData(handle_0, i2cReg_1, wVal_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cReadByteData_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cReadByteData': wrong number of arguments (%d for 2)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = i2cReadByteData(handle_0, i2cReg_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cReadWordData_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cReadWordData': wrong number of arguments (%d for 2)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = i2cReadWordData(handle_0, i2cReg_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cProcessCall_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cProcessCall': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int wVal_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = i2cProcessCall(handle_0, i2cReg_1, wVal_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cWriteBlockData_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cWriteBlockData': wrong number of arguments (%d for 4)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    char *buf_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    unsigned int count_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = i2cWriteBlockData(handle_0, i2cReg_1, buf_2, count_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cReadBlockData_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cReadBlockData': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    char *buf_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    int ret_val = i2cReadBlockData(handle_0, i2cReg_1, buf_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cBlockProcessCall_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cBlockProcessCall': wrong number of arguments (%d for 4)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    char *buf_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    unsigned int count_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = i2cBlockProcessCall(handle_0, i2cReg_1, buf_2, count_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cReadI2CBlockData_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cReadI2CBlockData': wrong number of arguments (%d for 4)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    char *buf_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    unsigned int count_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = i2cReadI2CBlockData(handle_0, i2cReg_1, buf_2, count_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cWriteI2CBlockData_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cWriteI2CBlockData': wrong number of arguments (%d for 4)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int i2cReg_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    char *buf_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    unsigned int count_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = i2cWriteI2CBlockData(handle_0, i2cReg_1, buf_2, count_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cReadDevice_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cReadDevice': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = i2cReadDevice(handle_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cWriteDevice_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cWriteDevice': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = i2cWriteDevice(handle_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cSwitchCombined_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cSwitchCombined': wrong number of arguments (%d for 1)", argc);
    int setting_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    i2cSwitchCombined(setting_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_i2cSegments_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cSegments': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    pi_i2c_msg_t *segs_1 = drb_ffi__ZTSP3$_2_FromRuby(state, args[1]);
    unsigned int numSegs_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = i2cSegments(handle_0, segs_1, numSegs_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_i2cZip_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'i2cZip': wrong number of arguments (%d for 5)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *inBuf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int inLen_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    char *outBuf_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    unsigned int outLen_4 = drb_ffi__ZTSj_FromRuby(state, args[4]);
    int ret_val = i2cZip(handle_0, inBuf_1, inLen_2, outBuf_3, outLen_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bbI2COpen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bbI2COpen': wrong number of arguments (%d for 3)", argc);
    unsigned int SDA_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int SCL_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int baud_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = bbI2COpen(SDA_0, SCL_1, baud_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bbI2CClose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bbI2CClose': wrong number of arguments (%d for 1)", argc);
    unsigned int SDA_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = bbI2CClose(SDA_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bbI2CZip_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bbI2CZip': wrong number of arguments (%d for 5)", argc);
    unsigned int SDA_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *inBuf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int inLen_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    char *outBuf_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    unsigned int outLen_4 = drb_ffi__ZTSj_FromRuby(state, args[4]);
    int ret_val = bbI2CZip(SDA_0, inBuf_1, inLen_2, outBuf_3, outLen_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bscXfer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bscXfer': wrong number of arguments (%d for 1)", argc);
    bsc_xfer_t *bsc_xfer_0 = drb_ffi__ZTSP3$_3_FromRuby(state, args[0]);
    int ret_val = bscXfer(bsc_xfer_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bbSPIOpen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bbSPIOpen': wrong number of arguments (%d for 6)", argc);
    unsigned int CS_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int MISO_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int MOSI_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    unsigned int SCLK_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    unsigned int baud_4 = drb_ffi__ZTSj_FromRuby(state, args[4]);
    unsigned int spiFlags_5 = drb_ffi__ZTSj_FromRuby(state, args[5]);
    int ret_val = bbSPIOpen(CS_0, MISO_1, MOSI_2, SCLK_3, baud_4, spiFlags_5);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bbSPIClose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bbSPIClose': wrong number of arguments (%d for 1)", argc);
    unsigned int CS_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = bbSPIClose(CS_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_bbSPIXfer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'bbSPIXfer': wrong number of arguments (%d for 4)", argc);
    unsigned int CS_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *inBuf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *outBuf_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    unsigned int count_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = bbSPIXfer(CS_0, inBuf_1, outBuf_2, count_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_spiOpen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'spiOpen': wrong number of arguments (%d for 3)", argc);
    unsigned int spiChan_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int baud_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int spiFlags_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = spiOpen(spiChan_0, baud_1, spiFlags_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_spiClose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'spiClose': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = spiClose(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_spiRead_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'spiRead': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = spiRead(handle_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_spiWrite_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'spiWrite': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = spiWrite(handle_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_spiXfer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'spiXfer': wrong number of arguments (%d for 4)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *txBuf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *rxBuf_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    unsigned int count_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = spiXfer(handle_0, txBuf_1, rxBuf_2, count_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_serOpen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'serOpen': wrong number of arguments (%d for 3)", argc);
    char *sertty_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    unsigned int baud_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int serFlags_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = serOpen(sertty_0, baud_1, serFlags_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_serClose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'serClose': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = serClose(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_serWriteByte_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'serWriteByte': wrong number of arguments (%d for 2)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int bVal_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = serWriteByte(handle_0, bVal_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_serReadByte_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'serReadByte': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = serReadByte(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_serWrite_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'serWrite': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = serWrite(handle_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_serRead_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'serRead': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = serRead(handle_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_serDataAvailable_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'serDataAvailable': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = serDataAvailable(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioTrigger_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioTrigger': wrong number of arguments (%d for 3)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int pulseLen_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int level_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = gpioTrigger(user_gpio_0, pulseLen_1, level_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetWatchdog_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetWatchdog': wrong number of arguments (%d for 2)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int timeout_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioSetWatchdog(user_gpio_0, timeout_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioNoiseFilter_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioNoiseFilter': wrong number of arguments (%d for 3)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int steady_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int active_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = gpioNoiseFilter(user_gpio_0, steady_1, active_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioGlitchFilter_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioGlitchFilter': wrong number of arguments (%d for 2)", argc);
    unsigned int user_gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int steady_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioGlitchFilter(user_gpio_0, steady_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetGetSamplesFunc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetGetSamplesFunc': wrong number of arguments (%d for 2)", argc);
    void (*f_0)(const gpioSample_t *, int) = drb_ffi__ZTSPFvPK3$_4iE_FromRuby(state, args[0]);
    int bits_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = gpioSetGetSamplesFunc(f_0, bits_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetGetSamplesFuncEx_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetGetSamplesFuncEx': wrong number of arguments (%d for 3)", argc);
    void (*f_0)(const gpioSample_t *, int, void *) = drb_ffi__ZTSPFvPK3$_4iPvE_FromRuby(state, args[0]);
    int bits_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *userdata_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    int ret_val = gpioSetGetSamplesFuncEx(f_0, bits_1, userdata_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetTimerFunc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetTimerFunc': wrong number of arguments (%d for 3)", argc);
    unsigned int timer_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int millis_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    void (*f_2)(void) = drb_ffi__ZTSPFvvE_FromRuby(state, args[2]);
    int ret_val = gpioSetTimerFunc(timer_0, millis_1, f_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetTimerFuncEx_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetTimerFuncEx': wrong number of arguments (%d for 4)", argc);
    unsigned int timer_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int millis_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    void (*f_2)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[2]);
    void *userdata_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int ret_val = gpioSetTimerFuncEx(timer_0, millis_1, f_2, userdata_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioStartThread_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioStartThread': wrong number of arguments (%d for 2)", argc);
    gpioThreadFunc_t *f_0 = drb_ffi__ZTSPFPvS_E_FromRuby(state, args[0]);
    void *userdata_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int *ret_val = gpioStartThread(f_0, userdata_1);
    return drb_ffi__ZTSPi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioStopThread_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioStopThread': wrong number of arguments (%d for 1)", argc);
    int *pth_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    gpioStopThread(pth_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_gpioStoreScript_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioStoreScript': wrong number of arguments (%d for 1)", argc);
    char *script_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = gpioStoreScript(script_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioRunScript_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioRunScript': wrong number of arguments (%d for 3)", argc);
    unsigned int script_id_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int numPar_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int *param_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    int ret_val = gpioRunScript(script_id_0, numPar_1, param_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioUpdateScript_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioUpdateScript': wrong number of arguments (%d for 3)", argc);
    unsigned int script_id_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int numPar_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int *param_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    int ret_val = gpioUpdateScript(script_id_0, numPar_1, param_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioScriptStatus_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioScriptStatus': wrong number of arguments (%d for 2)", argc);
    unsigned int script_id_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int *param_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = gpioScriptStatus(script_id_0, param_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioStopScript_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioStopScript': wrong number of arguments (%d for 1)", argc);
    unsigned int script_id_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioStopScript(script_id_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioDeleteScript_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioDeleteScript': wrong number of arguments (%d for 1)", argc);
    unsigned int script_id_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioDeleteScript(script_id_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetSignalFunc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetSignalFunc': wrong number of arguments (%d for 2)", argc);
    unsigned int signum_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    void (*f_1)(int) = drb_ffi__ZTSPFviE_FromRuby(state, args[1]);
    int ret_val = gpioSetSignalFunc(signum_0, f_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetSignalFuncEx_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetSignalFuncEx': wrong number of arguments (%d for 3)", argc);
    unsigned int signum_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    void (*f_1)(int, void *) = drb_ffi__ZTSPFviPvE_FromRuby(state, args[1]);
    void *userdata_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    int ret_val = gpioSetSignalFuncEx(signum_0, f_1, userdata_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioRead_Bits_0_31_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioRead_Bits_0_31': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioRead_Bits_0_31();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioRead_Bits_32_53_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioRead_Bits_32_53': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioRead_Bits_32_53();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWrite_Bits_0_31_Clear_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWrite_Bits_0_31_Clear': wrong number of arguments (%d for 1)", argc);
    int bits_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = gpioWrite_Bits_0_31_Clear(bits_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWrite_Bits_32_53_Clear_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWrite_Bits_32_53_Clear': wrong number of arguments (%d for 1)", argc);
    int bits_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = gpioWrite_Bits_32_53_Clear(bits_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWrite_Bits_0_31_Set_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWrite_Bits_0_31_Set': wrong number of arguments (%d for 1)", argc);
    int bits_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = gpioWrite_Bits_0_31_Set(bits_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioWrite_Bits_32_53_Set_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioWrite_Bits_32_53_Set': wrong number of arguments (%d for 1)", argc);
    int bits_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = gpioWrite_Bits_32_53_Set(bits_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioHardwareClock_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioHardwareClock': wrong number of arguments (%d for 2)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int clkfreq_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioHardwareClock(gpio_0, clkfreq_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioHardwarePWM_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioHardwarePWM': wrong number of arguments (%d for 3)", argc);
    unsigned int gpio_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int PWMfreq_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int PWMduty_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = gpioHardwarePWM(gpio_0, PWMfreq_1, PWMduty_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioTime_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioTime': wrong number of arguments (%d for 3)", argc);
    unsigned int timetype_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int *seconds_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int *micros_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    int ret_val = gpioTime(timetype_0, seconds_1, micros_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSleep_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSleep': wrong number of arguments (%d for 3)", argc);
    unsigned int timetype_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int seconds_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int micros_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = gpioSleep(timetype_0, seconds_1, micros_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioDelay_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioDelay': wrong number of arguments (%d for 1)", argc);
    int micros_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = gpioDelay(micros_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioTick_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioTick': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioTick();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioHardwareRevision_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioHardwareRevision': wrong number of arguments (%d for 0)", argc);
    unsigned int ret_val = gpioHardwareRevision();
    return drb_ffi__ZTSj_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioVersion_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioVersion': wrong number of arguments (%d for 0)", argc);
    unsigned int ret_val = gpioVersion();
    return drb_ffi__ZTSj_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioGetPad_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioGetPad': wrong number of arguments (%d for 1)", argc);
    unsigned int pad_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioGetPad(pad_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioSetPad_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioSetPad': wrong number of arguments (%d for 2)", argc);
    unsigned int pad_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int padStrength_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioSetPad(pad_0, padStrength_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_eventMonitor_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'eventMonitor': wrong number of arguments (%d for 2)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int bits_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = eventMonitor(handle_0, bits_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_eventSetFunc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'eventSetFunc': wrong number of arguments (%d for 2)", argc);
    unsigned int event_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    void (*f_1)(int, int) = drb_ffi__ZTSPFviiE_FromRuby(state, args[1]);
    int ret_val = eventSetFunc(event_0, f_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_eventSetFuncEx_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'eventSetFuncEx': wrong number of arguments (%d for 3)", argc);
    unsigned int event_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    void (*f_1)(int, int, void *) = drb_ffi__ZTSPFviiPvE_FromRuby(state, args[1]);
    void *userdata_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    int ret_val = eventSetFuncEx(event_0, f_1, userdata_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_eventTrigger_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'eventTrigger': wrong number of arguments (%d for 1)", argc);
    unsigned int event_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = eventTrigger(event_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_shell_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'shell': wrong number of arguments (%d for 2)", argc);
    char *scriptName_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *scriptString_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = shell(scriptName_0, scriptString_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fileOpen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fileOpen': wrong number of arguments (%d for 2)", argc);
    char *file_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    unsigned int mode_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = fileOpen(file_0, mode_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fileClose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fileClose': wrong number of arguments (%d for 1)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = fileClose(handle_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fileWrite_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fileWrite': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = fileWrite(handle_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fileRead_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fileRead': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = fileRead(handle_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fileSeek_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fileSeek': wrong number of arguments (%d for 3)", argc);
    unsigned int handle_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int seekOffset_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int seekFrom_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = fileSeek(handle_0, seekOffset_1, seekFrom_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fileList_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fileList': wrong number of arguments (%d for 3)", argc);
    char *fpat_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int count_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = fileList(fpat_0, buf_1, count_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgBufferSize_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgBufferSize': wrong number of arguments (%d for 1)", argc);
    unsigned int cfgMillis_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioCfgBufferSize(cfgMillis_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgClock_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgClock': wrong number of arguments (%d for 3)", argc);
    unsigned int cfgMicros_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int cfgPeripheral_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int cfgSource_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = gpioCfgClock(cfgMicros_0, cfgPeripheral_1, cfgSource_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgDMAchannel_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgDMAchannel': wrong number of arguments (%d for 1)", argc);
    unsigned int DMAchannel_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioCfgDMAchannel(DMAchannel_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgDMAchannels_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgDMAchannels': wrong number of arguments (%d for 2)", argc);
    unsigned int primaryChannel_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int secondaryChannel_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int ret_val = gpioCfgDMAchannels(primaryChannel_0, secondaryChannel_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgPermissions_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgPermissions': wrong number of arguments (%d for 1)", argc);
    int updateMask_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = gpioCfgPermissions(updateMask_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgSocketPort_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgSocketPort': wrong number of arguments (%d for 1)", argc);
    unsigned int port_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioCfgSocketPort(port_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgInterfaces_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgInterfaces': wrong number of arguments (%d for 1)", argc);
    unsigned int ifFlags_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioCfgInterfaces(ifFlags_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgMemAlloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgMemAlloc': wrong number of arguments (%d for 1)", argc);
    unsigned int memAllocMode_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    int ret_val = gpioCfgMemAlloc(memAllocMode_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgNetAddr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgNetAddr': wrong number of arguments (%d for 2)", argc);
    int numSockAddr_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *sockAddr_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = gpioCfgNetAddr(numSockAddr_0, sockAddr_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgGetInternals_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgGetInternals': wrong number of arguments (%d for 0)", argc);
    int ret_val = gpioCfgGetInternals();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCfgSetInternals_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCfgSetInternals': wrong number of arguments (%d for 1)", argc);
    int cfgVal_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = gpioCfgSetInternals(cfgVal_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCustom1_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCustom1': wrong number of arguments (%d for 4)", argc);
    unsigned int arg1_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    unsigned int arg2_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    char *argx_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    unsigned int argc_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    int ret_val = gpioCustom1(arg1_0, arg2_1, argx_2, argc_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_gpioCustom2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'gpioCustom2': wrong number of arguments (%d for 5)", argc);
    unsigned int arg1_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    char *argx_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int argc_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    char *retBuf_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    unsigned int retMax_4 = drb_ffi__ZTSj_FromRuby(state, args[4]);
    int ret_val = gpioCustom2(arg1_0, argx_1, argc_2, retBuf_3, retMax_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rawWaveAddSPI_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 8)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveAddSPI': wrong number of arguments (%d for 8)", argc);
    rawSPI_t *spi_0 = drb_ffi__ZTSP8rawSPI_t_FromRuby(state, args[0]);
    unsigned int offset_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    unsigned int spiSS_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    char *buf_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    unsigned int spiTxBits_4 = drb_ffi__ZTSj_FromRuby(state, args[4]);
    unsigned int spiBitFirst_5 = drb_ffi__ZTSj_FromRuby(state, args[5]);
    unsigned int spiBitLast_6 = drb_ffi__ZTSj_FromRuby(state, args[6]);
    unsigned int spiBits_7 = drb_ffi__ZTSj_FromRuby(state, args[7]);
    int ret_val = rawWaveAddSPI(spi_0, offset_1, spiSS_2, buf_3, spiTxBits_4, spiBitFirst_5, spiBitLast_6, spiBits_7);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rawWaveAddGeneric_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveAddGeneric': wrong number of arguments (%d for 2)", argc);
    unsigned int numPulses_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    rawWave_t *pulses_1 = drb_ffi__ZTSP3$_5_FromRuby(state, args[1]);
    int ret_val = rawWaveAddGeneric(numPulses_0, pulses_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rawWaveCB_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveCB': wrong number of arguments (%d for 0)", argc);
    unsigned int ret_val = rawWaveCB();
    return drb_ffi__ZTSj_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rawWaveCBAdr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveCBAdr': wrong number of arguments (%d for 1)", argc);
    int cbNum_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    rawCbs_t *ret_val = rawWaveCBAdr(cbNum_0);
    return drb_ffi__ZTSP3$_6_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rawWaveGetOOL_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveGetOOL': wrong number of arguments (%d for 1)", argc);
    int pos_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = rawWaveGetOOL(pos_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rawWaveSetOOL_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveSetOOL': wrong number of arguments (%d for 2)", argc);
    int pos_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int lVal_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    rawWaveSetOOL(pos_0, lVal_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_rawWaveGetOut_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveGetOut': wrong number of arguments (%d for 1)", argc);
    int pos_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = rawWaveGetOut(pos_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rawWaveSetOut_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveSetOut': wrong number of arguments (%d for 2)", argc);
    int pos_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int lVal_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    rawWaveSetOut(pos_0, lVal_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_rawWaveGetIn_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveGetIn': wrong number of arguments (%d for 1)", argc);
    int pos_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = rawWaveGetIn(pos_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rawWaveSetIn_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveSetIn': wrong number of arguments (%d for 2)", argc);
    int pos_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int lVal_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    rawWaveSetIn(pos_0, lVal_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_rawWaveInfo_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawWaveInfo': wrong number of arguments (%d for 1)", argc);
    int wave_id_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    rawWaveInfo_t ret_val = rawWaveInfo(wave_id_0);
    return drb_ffi__ZTS3$_7_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getBitInBytes_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'getBitInBytes': wrong number of arguments (%d for 3)", argc);
    int bitPos_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int numBits_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = getBitInBytes(bitPos_0, buf_1, numBits_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_putBitInBytes_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'putBitInBytes': wrong number of arguments (%d for 3)", argc);
    int bitPos_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    char *buf_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int bit_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    putBitInBytes(bitPos_0, buf_1, bit_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_time_time_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'time_time': wrong number of arguments (%d for 0)", argc);
    double ret_val = time_time();
    return drb_ffi__ZTSd_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_time_sleep_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'time_sleep': wrong number of arguments (%d for 1)", argc);
    double seconds_0 = drb_ffi__ZTSd_FromRuby(state, args[0]);
    time_sleep(seconds_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_rawDumpWave_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawDumpWave': wrong number of arguments (%d for 0)", argc);
    rawDumpWave();
    return mrb_nil_value();
}
static mrb_value drb_ffi_rawDumpScript_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rawDumpScript': wrong number of arguments (%d for 1)", argc);
    unsigned int script_id_0 = drb_ffi__ZTSj_FromRuby(state, args[0]);
    rawDumpScript(script_id_0);
    return mrb_nil_value();
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
    struct RClass *module = drb_api->mrb_define_module_under(state, FFI, "PIGPIO");
    struct RClass *object_class = state->object_class;
    drb_api->mrb_define_module_function(state, module, "nanosleep", drb_ffi_nanosleep_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "clock_nanosleep", drb_ffi_clock_nanosleep_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "pthread_exit", drb_ffi_pthread_exit_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "pthread_join", drb_ffi_pthread_join_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "pthread_setcancelstate", drb_ffi_pthread_setcancelstate_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "pthread_setcanceltype", drb_ffi_pthread_setcanceltype_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "pthread_cancel", drb_ffi_pthread_cancel_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "pthread_testcancel", drb_ffi_pthread_testcancel_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "__pthread_register_cancel", drb_ffi___pthread_register_cancel_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "__pthread_unregister_cancel", drb_ffi___pthread_unregister_cancel_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "__pthread_unwind_next", drb_ffi___pthread_unwind_next_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioInitialise", drb_ffi_gpioInitialise_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioTerminate", drb_ffi_gpioTerminate_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioSetMode", drb_ffi_gpioSetMode_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioGetMode", drb_ffi_gpioGetMode_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioSetPullUpDown", drb_ffi_gpioSetPullUpDown_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioRead", drb_ffi_gpioRead_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioWrite", drb_ffi_gpioWrite_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioPWM", drb_ffi_gpioPWM_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioGetPWMdutycycle", drb_ffi_gpioGetPWMdutycycle_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioSetPWMrange", drb_ffi_gpioSetPWMrange_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioGetPWMrange", drb_ffi_gpioGetPWMrange_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioGetPWMrealRange", drb_ffi_gpioGetPWMrealRange_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioSetPWMfrequency", drb_ffi_gpioSetPWMfrequency_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioGetPWMfrequency", drb_ffi_gpioGetPWMfrequency_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioServo", drb_ffi_gpioServo_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioGetServoPulsewidth", drb_ffi_gpioGetServoPulsewidth_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioSetAlertFunc", drb_ffi_gpioSetAlertFunc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioSetAlertFuncEx", drb_ffi_gpioSetAlertFuncEx_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioSetISRFunc", drb_ffi_gpioSetISRFunc_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "gpioSetISRFuncEx", drb_ffi_gpioSetISRFuncEx_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "gpioNotifyOpen", drb_ffi_gpioNotifyOpen_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioNotifyOpenWithSize", drb_ffi_gpioNotifyOpenWithSize_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioNotifyBegin", drb_ffi_gpioNotifyBegin_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioNotifyPause", drb_ffi_gpioNotifyPause_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioNotifyClose", drb_ffi_gpioNotifyClose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioWaveClear", drb_ffi_gpioWaveClear_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveAddNew", drb_ffi_gpioWaveAddNew_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveAddGeneric", drb_ffi_gpioWaveAddGeneric_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioWaveAddSerial", drb_ffi_gpioWaveAddSerial_Binding, MRB_ARGS_REQ(7));
    drb_api->mrb_define_module_function(state, module, "gpioWaveCreate", drb_ffi_gpioWaveCreate_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveCreatePad", drb_ffi_gpioWaveCreatePad_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioWaveDelete", drb_ffi_gpioWaveDelete_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioWaveTxSend", drb_ffi_gpioWaveTxSend_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioWaveChain", drb_ffi_gpioWaveChain_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioWaveTxAt", drb_ffi_gpioWaveTxAt_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveTxBusy", drb_ffi_gpioWaveTxBusy_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveTxStop", drb_ffi_gpioWaveTxStop_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetMicros", drb_ffi_gpioWaveGetMicros_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetHighMicros", drb_ffi_gpioWaveGetHighMicros_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetMaxMicros", drb_ffi_gpioWaveGetMaxMicros_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetPulses", drb_ffi_gpioWaveGetPulses_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetHighPulses", drb_ffi_gpioWaveGetHighPulses_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetMaxPulses", drb_ffi_gpioWaveGetMaxPulses_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetCbs", drb_ffi_gpioWaveGetCbs_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetHighCbs", drb_ffi_gpioWaveGetHighCbs_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWaveGetMaxCbs", drb_ffi_gpioWaveGetMaxCbs_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioSerialReadOpen", drb_ffi_gpioSerialReadOpen_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioSerialReadInvert", drb_ffi_gpioSerialReadInvert_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioSerialRead", drb_ffi_gpioSerialRead_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioSerialReadClose", drb_ffi_gpioSerialReadClose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "i2cOpen", drb_ffi_i2cOpen_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "i2cClose", drb_ffi_i2cClose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "i2cWriteQuick", drb_ffi_i2cWriteQuick_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "i2cWriteByte", drb_ffi_i2cWriteByte_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "i2cReadByte", drb_ffi_i2cReadByte_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "i2cWriteByteData", drb_ffi_i2cWriteByteData_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "i2cWriteWordData", drb_ffi_i2cWriteWordData_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "i2cReadByteData", drb_ffi_i2cReadByteData_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "i2cReadWordData", drb_ffi_i2cReadWordData_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "i2cProcessCall", drb_ffi_i2cProcessCall_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "i2cWriteBlockData", drb_ffi_i2cWriteBlockData_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "i2cReadBlockData", drb_ffi_i2cReadBlockData_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "i2cBlockProcessCall", drb_ffi_i2cBlockProcessCall_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "i2cReadI2CBlockData", drb_ffi_i2cReadI2CBlockData_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "i2cWriteI2CBlockData", drb_ffi_i2cWriteI2CBlockData_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "i2cReadDevice", drb_ffi_i2cReadDevice_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "i2cWriteDevice", drb_ffi_i2cWriteDevice_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "i2cSwitchCombined", drb_ffi_i2cSwitchCombined_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "i2cSegments", drb_ffi_i2cSegments_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "i2cZip", drb_ffi_i2cZip_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "bbI2COpen", drb_ffi_bbI2COpen_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "bbI2CClose", drb_ffi_bbI2CClose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bbI2CZip", drb_ffi_bbI2CZip_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "bscXfer", drb_ffi_bscXfer_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bbSPIOpen", drb_ffi_bbSPIOpen_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "bbSPIClose", drb_ffi_bbSPIClose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bbSPIXfer", drb_ffi_bbSPIXfer_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "spiOpen", drb_ffi_spiOpen_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "spiClose", drb_ffi_spiClose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "spiRead", drb_ffi_spiRead_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "spiWrite", drb_ffi_spiWrite_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "spiXfer", drb_ffi_spiXfer_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "serOpen", drb_ffi_serOpen_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "serClose", drb_ffi_serClose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "serWriteByte", drb_ffi_serWriteByte_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "serReadByte", drb_ffi_serReadByte_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "serWrite", drb_ffi_serWrite_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "serRead", drb_ffi_serRead_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "serDataAvailable", drb_ffi_serDataAvailable_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioTrigger", drb_ffi_gpioTrigger_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioSetWatchdog", drb_ffi_gpioSetWatchdog_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioNoiseFilter", drb_ffi_gpioNoiseFilter_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioGlitchFilter", drb_ffi_gpioGlitchFilter_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioSetGetSamplesFunc", drb_ffi_gpioSetGetSamplesFunc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioSetGetSamplesFuncEx", drb_ffi_gpioSetGetSamplesFuncEx_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioSetTimerFunc", drb_ffi_gpioSetTimerFunc_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioSetTimerFuncEx", drb_ffi_gpioSetTimerFuncEx_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "gpioStartThread", drb_ffi_gpioStartThread_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioStopThread", drb_ffi_gpioStopThread_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioStoreScript", drb_ffi_gpioStoreScript_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioRunScript", drb_ffi_gpioRunScript_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioUpdateScript", drb_ffi_gpioUpdateScript_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioScriptStatus", drb_ffi_gpioScriptStatus_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioStopScript", drb_ffi_gpioStopScript_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioDeleteScript", drb_ffi_gpioDeleteScript_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioSetSignalFunc", drb_ffi_gpioSetSignalFunc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioSetSignalFuncEx", drb_ffi_gpioSetSignalFuncEx_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioRead_Bits_0_31", drb_ffi_gpioRead_Bits_0_31_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioRead_Bits_32_53", drb_ffi_gpioRead_Bits_32_53_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioWrite_Bits_0_31_Clear", drb_ffi_gpioWrite_Bits_0_31_Clear_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioWrite_Bits_32_53_Clear", drb_ffi_gpioWrite_Bits_32_53_Clear_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioWrite_Bits_0_31_Set", drb_ffi_gpioWrite_Bits_0_31_Set_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioWrite_Bits_32_53_Set", drb_ffi_gpioWrite_Bits_32_53_Set_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioHardwareClock", drb_ffi_gpioHardwareClock_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioHardwarePWM", drb_ffi_gpioHardwarePWM_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioTime", drb_ffi_gpioTime_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioSleep", drb_ffi_gpioSleep_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioDelay", drb_ffi_gpioDelay_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioTick", drb_ffi_gpioTick_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioHardwareRevision", drb_ffi_gpioHardwareRevision_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioVersion", drb_ffi_gpioVersion_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioGetPad", drb_ffi_gpioGetPad_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioSetPad", drb_ffi_gpioSetPad_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "eventMonitor", drb_ffi_eventMonitor_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "eventSetFunc", drb_ffi_eventSetFunc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "eventSetFuncEx", drb_ffi_eventSetFuncEx_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "eventTrigger", drb_ffi_eventTrigger_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "shell", drb_ffi_shell_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "fileOpen", drb_ffi_fileOpen_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "fileClose", drb_ffi_fileClose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "fileWrite", drb_ffi_fileWrite_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "fileRead", drb_ffi_fileRead_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "fileSeek", drb_ffi_fileSeek_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "fileList", drb_ffi_fileList_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioCfgBufferSize", drb_ffi_gpioCfgBufferSize_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioCfgClock", drb_ffi_gpioCfgClock_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "gpioCfgDMAchannel", drb_ffi_gpioCfgDMAchannel_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioCfgDMAchannels", drb_ffi_gpioCfgDMAchannels_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioCfgPermissions", drb_ffi_gpioCfgPermissions_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioCfgSocketPort", drb_ffi_gpioCfgSocketPort_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioCfgInterfaces", drb_ffi_gpioCfgInterfaces_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioCfgMemAlloc", drb_ffi_gpioCfgMemAlloc_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioCfgNetAddr", drb_ffi_gpioCfgNetAddr_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "gpioCfgGetInternals", drb_ffi_gpioCfgGetInternals_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "gpioCfgSetInternals", drb_ffi_gpioCfgSetInternals_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "gpioCustom1", drb_ffi_gpioCustom1_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "gpioCustom2", drb_ffi_gpioCustom2_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "rawWaveAddSPI", drb_ffi_rawWaveAddSPI_Binding, MRB_ARGS_REQ(8));
    drb_api->mrb_define_module_function(state, module, "rawWaveAddGeneric", drb_ffi_rawWaveAddGeneric_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "rawWaveCB", drb_ffi_rawWaveCB_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "rawWaveCBAdr", drb_ffi_rawWaveCBAdr_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "rawWaveGetOOL", drb_ffi_rawWaveGetOOL_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "rawWaveSetOOL", drb_ffi_rawWaveSetOOL_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "rawWaveGetOut", drb_ffi_rawWaveGetOut_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "rawWaveSetOut", drb_ffi_rawWaveSetOut_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "rawWaveGetIn", drb_ffi_rawWaveGetIn_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "rawWaveSetIn", drb_ffi_rawWaveSetIn_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "rawWaveInfo", drb_ffi_rawWaveInfo_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "getBitInBytes", drb_ffi_getBitInBytes_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "putBitInBytes", drb_ffi_putBitInBytes_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "time_time", drb_ffi_time_time_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "time_sleep", drb_ffi_time_sleep_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "rawDumpWave", drb_ffi_rawDumpWave_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "rawDumpScript", drb_ffi_rawDumpScript_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_initialise", drb_ffi_bridge_gpio_initialise_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_terminate", drb_ffi_bridge_gpio_terminate_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_set_mode", drb_ffi_bridge_gpio_set_mode_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_set_pull_up_down", drb_ffi_bridge_gpio_set_pull_up_down_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_glitch_filter", drb_ffi_bridge_gpio_glitch_filter_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_read", drb_ffi_bridge_gpio_read_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_write", drb_ffi_bridge_gpio_write_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_initialise", drb_ffi_bridge_gpio_initialise_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_terminate", drb_ffi_bridge_gpio_terminate_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_set_mode", drb_ffi_bridge_gpio_set_mode_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_set_pull_up_down", drb_ffi_bridge_gpio_set_pull_up_down_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_glitch_filter", drb_ffi_bridge_gpio_glitch_filter_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_read", drb_ffi_bridge_gpio_read_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_write", drb_ffi_bridge_gpio_write_Binding, MRB_ARGS_REQ(2));
    struct RClass *TimespecPointerClass = drb_api->mrb_define_class_under(state, module, "TimespecPointer", object_class);
    drb_api->mrb_define_class_method(state, TimespecPointerClass, "new", drb_ffi__ZTSPZ9nanosleepE8timespec_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, TimespecPointerClass, "value", drb_ffi__ZTSPZ9nanosleepE8timespec_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, TimespecPointerClass, "[]", drb_ffi__ZTSPZ9nanosleepE8timespec_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, TimespecPointerClass, "[]=", drb_ffi__ZTSPZ9nanosleepE8timespec_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, TimespecPointerClass, "nil?", drb_ffi__ZTSPZ9nanosleepE8timespec_IsNil, MRB_ARGS_REQ(0));
    struct RClass *VoidPointerClass = drb_api->mrb_define_class_under(state, module, "VoidPointer", object_class);
    struct RClass *VoidPointerPointerClass = drb_api->mrb_define_class_under(state, module, "VoidPointerPointer", object_class);
    drb_api->mrb_define_class_method(state, VoidPointerPointerClass, "new", drb_ffi__ZTSPPv_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, VoidPointerPointerClass, "value", drb_ffi__ZTSPPv_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, VoidPointerPointerClass, "[]", drb_ffi__ZTSPPv_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, VoidPointerPointerClass, "[]=", drb_ffi__ZTSPPv_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, VoidPointerPointerClass, "nil?", drb_ffi__ZTSPPv_IsNil, MRB_ARGS_REQ(0));
    struct RClass *IntPointerClass = drb_api->mrb_define_class_under(state, module, "IntPointer", object_class);
    drb_api->mrb_define_class_method(state, IntPointerClass, "new", drb_ffi__ZTSPi_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, IntPointerClass, "value", drb_ffi__ZTSPi_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, IntPointerClass, "[]", drb_ffi__ZTSPi_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, IntPointerClass, "[]=", drb_ffi__ZTSPi_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, IntPointerClass, "nil?", drb_ffi__ZTSPi_IsNil, MRB_ARGS_REQ(0));
    struct RClass *PointerClass = drb_api->mrb_define_class_under(state, module, "Pointer", object_class);
    drb_api->mrb_define_class_method(state, PointerClass, "new", drb_ffi__ZTSP3$_0_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, PointerClass, "value", drb_ffi__ZTSP3$_0_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, PointerClass, "[]", drb_ffi__ZTSP3$_0_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, PointerClass, "[]=", drb_ffi__ZTSP3$_0_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, PointerClass, "nil?", drb_ffi__ZTSP3$_0_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_0PointerClass = drb_api->mrb_define_class_under(state, module, "Function_0Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_0PointerClass, "new", drb_ffi__ZTSPFviiiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_0PointerClass, "value", drb_ffi__ZTSPFviiiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_0PointerClass, "[]", drb_ffi__ZTSPFviiiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_0PointerClass, "[]=", drb_ffi__ZTSPFviiiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_0PointerClass, "nil?", drb_ffi__ZTSPFviiiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_1PointerClass = drb_api->mrb_define_class_under(state, module, "Function_1Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_1PointerClass, "new", drb_ffi__ZTSPFviiiPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_1PointerClass, "value", drb_ffi__ZTSPFviiiPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_1PointerClass, "[]", drb_ffi__ZTSPFviiiPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_1PointerClass, "[]=", drb_ffi__ZTSPFviiiPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_1PointerClass, "nil?", drb_ffi__ZTSPFviiiPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *CharPointerClass = drb_api->mrb_define_class_under(state, module, "CharPointer", object_class);
    drb_api->mrb_define_class_method(state, CharPointerClass, "new", drb_ffi__ZTSPc_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "value", drb_ffi__ZTSPc_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "[]", drb_ffi__ZTSPc_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, CharPointerClass, "[]=", drb_ffi__ZTSPc_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, CharPointerClass, "nil?", drb_ffi__ZTSPc_IsNil, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "str", drb_ffi__ZTSPc_GetString, MRB_ARGS_REQ(0));
    struct RClass *Function_2PointerClass = drb_api->mrb_define_class_under(state, module, "Function_2Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_2PointerClass, "new", drb_ffi__ZTSPFvPK3$_4iE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_2PointerClass, "value", drb_ffi__ZTSPFvPK3$_4iE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_2PointerClass, "[]", drb_ffi__ZTSPFvPK3$_4iE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_2PointerClass, "[]=", drb_ffi__ZTSPFvPK3$_4iE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_2PointerClass, "nil?", drb_ffi__ZTSPFvPK3$_4iE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_3PointerClass = drb_api->mrb_define_class_under(state, module, "Function_3Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_3PointerClass, "new", drb_ffi__ZTSPFvPK3$_4iPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_3PointerClass, "value", drb_ffi__ZTSPFvPK3$_4iPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_3PointerClass, "[]", drb_ffi__ZTSPFvPK3$_4iPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_3PointerClass, "[]=", drb_ffi__ZTSPFvPK3$_4iPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_3PointerClass, "nil?", drb_ffi__ZTSPFvPK3$_4iPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_4PointerClass = drb_api->mrb_define_class_under(state, module, "Function_4Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_4PointerClass, "new", drb_ffi__ZTSPFvvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_4PointerClass, "value", drb_ffi__ZTSPFvvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_4PointerClass, "[]", drb_ffi__ZTSPFvvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_4PointerClass, "[]=", drb_ffi__ZTSPFvvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_4PointerClass, "nil?", drb_ffi__ZTSPFvvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_5PointerClass = drb_api->mrb_define_class_under(state, module, "Function_5Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_5PointerClass, "new", drb_ffi__ZTSPFvPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_5PointerClass, "value", drb_ffi__ZTSPFvPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_5PointerClass, "[]", drb_ffi__ZTSPFvPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_5PointerClass, "[]=", drb_ffi__ZTSPFvPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_5PointerClass, "nil?", drb_ffi__ZTSPFvPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_6PointerClass = drb_api->mrb_define_class_under(state, module, "Function_6Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_6PointerClass, "new", drb_ffi__ZTSPFPvS_E_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_6PointerClass, "value", drb_ffi__ZTSPFPvS_E_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_6PointerClass, "[]", drb_ffi__ZTSPFPvS_E_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_6PointerClass, "[]=", drb_ffi__ZTSPFPvS_E_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_6PointerClass, "nil?", drb_ffi__ZTSPFPvS_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_7PointerClass = drb_api->mrb_define_class_under(state, module, "Function_7Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_7PointerClass, "new", drb_ffi__ZTSPFviE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_7PointerClass, "value", drb_ffi__ZTSPFviE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_7PointerClass, "[]", drb_ffi__ZTSPFviE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_7PointerClass, "[]=", drb_ffi__ZTSPFviE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_7PointerClass, "nil?", drb_ffi__ZTSPFviE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_8PointerClass = drb_api->mrb_define_class_under(state, module, "Function_8Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_8PointerClass, "new", drb_ffi__ZTSPFviPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_8PointerClass, "value", drb_ffi__ZTSPFviPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_8PointerClass, "[]", drb_ffi__ZTSPFviPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_8PointerClass, "[]=", drb_ffi__ZTSPFviPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_8PointerClass, "nil?", drb_ffi__ZTSPFviPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_9PointerClass = drb_api->mrb_define_class_under(state, module, "Function_9Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_9PointerClass, "new", drb_ffi__ZTSPFviiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_9PointerClass, "value", drb_ffi__ZTSPFviiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_9PointerClass, "[]", drb_ffi__ZTSPFviiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_9PointerClass, "[]=", drb_ffi__ZTSPFviiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_9PointerClass, "nil?", drb_ffi__ZTSPFviiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_10PointerClass = drb_api->mrb_define_class_under(state, module, "Function_10Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_10PointerClass, "new", drb_ffi__ZTSPFviiPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_10PointerClass, "value", drb_ffi__ZTSPFviiPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_10PointerClass, "[]", drb_ffi__ZTSPFviiPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_10PointerClass, "[]=", drb_ffi__ZTSPFviiPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_10PointerClass, "nil?", drb_ffi__ZTSPFviiPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Class = drb_api->mrb_define_class_under(state, module, "", object_class);
    drb_api->mrb_define_class_method(state, Class, "new", drb_ffi__ZTS3$_7_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "botCB", drb_ffi__ZTS3$_7_botCB_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "botCB=", drb_ffi__ZTS3$_7_botCB_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "topCB", drb_ffi__ZTS3$_7_topCB_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "topCB=", drb_ffi__ZTS3$_7_topCB_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "botOOL", drb_ffi__ZTS3$_7_botOOL_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "botOOL=", drb_ffi__ZTS3$_7_botOOL_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "topOOL", drb_ffi__ZTS3$_7_topOOL_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "topOOL=", drb_ffi__ZTS3$_7_topOOL_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "deleted", drb_ffi__ZTS3$_7_deleted_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "deleted=", drb_ffi__ZTS3$_7_deleted_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "numCB", drb_ffi__ZTS3$_7_numCB_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "numCB=", drb_ffi__ZTS3$_7_numCB_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "numBOOL", drb_ffi__ZTS3$_7_numBOOL_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "numBOOL=", drb_ffi__ZTS3$_7_numBOOL_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "numTOOL", drb_ffi__ZTS3$_7_numTOOL_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "numTOOL=", drb_ffi__ZTS3$_7_numTOOL_Set, MRB_ARGS_REQ(1));
}
