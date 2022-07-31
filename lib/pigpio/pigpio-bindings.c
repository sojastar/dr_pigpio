#include <mruby.h>
#include <string.h>
#include <assert.h>
#include <mruby/string.h>
#include <mruby/data.h>
#include <dragonruby.h>
#include "lib/pigpio/pigpio-bridge.h"

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
static long drb_ffi__ZTSl_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSl_ToRuby(mrb_state *state, long value) {
    return mrb_fixnum_value(value);
}
static double drb_ffi__ZTSd_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_float(state, self);
    return mrb_float(self);
}
static mrb_value drb_ffi__ZTSd_ToRuby(mrb_state *state, double value) {
    return drb_api->drb_float_value(state, value);
}
struct drb_foreign_object_ZTSPPc {
    drb_foreign_object_kind kind;
    char **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPc = {"char**", drb_free_foreign_object_indirect};
static char **drb_ffi__ZTSPPc_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPPc);
    return ((struct drb_foreign_object_ZTSPPc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPc_ToRuby(mrb_state *state, char **value) {
    struct drb_foreign_object_ZTSPPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPPc);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS10mrb_value_ {
    drb_foreign_object_kind kind;
    union mrb_value_ value;
};
static mrb_data_type ForeignObjectType_ZTS10mrb_value_ = {"mrb_value_", drb_free_foreign_object_indirect};
static union mrb_value_ drb_ffi__ZTS10mrb_value__FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_value_");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS10mrb_value_);
    return ((struct drb_foreign_object_ZTS10mrb_value_ *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS10mrb_value__ToRuby(mrb_state *state, union mrb_value_ value) {
    struct drb_foreign_object_ZTS10mrb_value_ *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS10mrb_value_));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_value_");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS10mrb_value_);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS9mrb_value {
    drb_foreign_object_kind kind;
    mrb_value value;
};
static mrb_data_type ForeignObjectType_ZTS9mrb_value = {"mrb_value", drb_free_foreign_object_indirect};
static mrb_value drb_ffi__ZTS9mrb_value_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_value");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS9mrb_value);
    return ((struct drb_foreign_object_ZTS9mrb_value *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS9mrb_value_ToRuby(mrb_state *state, mrb_value value) {
    struct drb_foreign_object_ZTS9mrb_value *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS9mrb_value));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_value");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS9mrb_value);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP9mrb_state {
    drb_foreign_object_kind kind;
    struct mrb_state *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP9mrb_state = {"mrb_state*", drb_free_foreign_object_indirect};
static struct mrb_state *drb_ffi__ZTSP9mrb_state_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_statePointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP9mrb_state);
    return ((struct drb_foreign_object_ZTSP9mrb_state *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP9mrb_state_ToRuby(mrb_state *state, struct mrb_state *value) {
    struct drb_foreign_object_ZTSP9mrb_state *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP9mrb_state));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_statePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP9mrb_state);
    return mrb_obj_value(rdata);
}
static enum mrb_vtype drb_ffi__ZTS9mrb_vtype_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTS9mrb_vtype_ToRuby(mrb_state *state, enum mrb_vtype value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPFiP9mrb_stateP6RBasicPvE {
    drb_foreign_object_kind kind;
    mrb_each_object_callback *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP9mrb_stateP6RBasicPvE = {"Function_0*", drb_free_foreign_object_indirect};
static mrb_each_object_callback *drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_0Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP9mrb_stateP6RBasicPvE);
    return ((struct drb_foreign_object_ZTSPFiP9mrb_stateP6RBasicPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_ToRuby(mrb_state *state, mrb_each_object_callback *value) {
    struct drb_foreign_object_ZTSPFiP9mrb_stateP6RBasicPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP9mrb_stateP6RBasicPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_0Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP9mrb_stateP6RBasicPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP11mrb_context {
    drb_foreign_object_kind kind;
    struct mrb_context *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP11mrb_context = {"mrb_context*", drb_free_foreign_object_indirect};
static struct mrb_context *drb_ffi__ZTSP11mrb_context_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_contextPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP11mrb_context);
    return ((struct drb_foreign_object_ZTSP11mrb_context *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP11mrb_context_ToRuby(mrb_state *state, struct mrb_context *value) {
    struct drb_foreign_object_ZTSP11mrb_context *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP11mrb_context));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_contextPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP11mrb_context);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP6RBasic {
    drb_foreign_object_kind kind;
    struct RBasic *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP6RBasic = {"RBasic*", drb_free_foreign_object_indirect};
static struct RBasic *drb_ffi__ZTSP6RBasic_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RBasicPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP6RBasic);
    return ((struct drb_foreign_object_ZTSP6RBasic *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP6RBasic_ToRuby(mrb_state *state, struct RBasic *value) {
    struct drb_foreign_object_ZTSP6RBasic *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6RBasic));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RBasicPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP6RBasic);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP6RClass {
    drb_foreign_object_kind kind;
    struct RClass *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP6RClass = {"RClass*", drb_free_foreign_object_indirect};
static struct RClass *drb_ffi__ZTSP6RClass_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RClassPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP6RClass);
    return ((struct drb_foreign_object_ZTSP6RClass *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP6RClass_ToRuby(mrb_state *state, struct RClass *value) {
    struct drb_foreign_object_ZTSP6RClass *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6RClass));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RClassPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP6RClass);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPF9mrb_valueP9mrb_stateS_E {
    drb_foreign_object_kind kind;
    mrb_value (*value)(struct mrb_state *, mrb_value);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPF9mrb_valueP9mrb_stateS_E = {"Function_1*", drb_free_foreign_object_indirect};
static mrb_value (*drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(mrb_state *state, mrb_value self))(struct mrb_state *, mrb_value) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_1Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPF9mrb_valueP9mrb_stateS_E);
    return ((struct drb_foreign_object_ZTSPF9mrb_valueP9mrb_stateS_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_ToRuby(mrb_state *state, mrb_value (*value)(struct mrb_state *, mrb_value)) {
    struct drb_foreign_object_ZTSPF9mrb_valueP9mrb_stateS_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPF9mrb_valueP9mrb_stateS_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_1Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPF9mrb_valueP9mrb_stateS_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP7RObject {
    drb_foreign_object_kind kind;
    struct RObject *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP7RObject = {"RObject*", drb_free_foreign_object_indirect};
static struct RObject *drb_ffi__ZTSP7RObject_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RObjectPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP7RObject);
    return ((struct drb_foreign_object_ZTSP7RObject *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP7RObject_ToRuby(mrb_state *state, struct RObject *value) {
    struct drb_foreign_object_ZTSP7RObject *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP7RObject));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RObjectPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP7RObject);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP9mrb_value {
    drb_foreign_object_kind kind;
    mrb_value *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP9mrb_value = {"mrb_value*", drb_free_foreign_object_indirect};
static mrb_value *drb_ffi__ZTSP9mrb_value_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_valuePointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP9mrb_value);
    return ((struct drb_foreign_object_ZTSP9mrb_value *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP9mrb_value_ToRuby(mrb_state *state, mrb_value *value) {
    struct drb_foreign_object_ZTSP9mrb_value *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP9mrb_value));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_valuePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP9mrb_value);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFPvP9mrb_stateS_iS_E {
    drb_foreign_object_kind kind;
    void *(*value)(struct mrb_state *, void *, int, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFPvP9mrb_stateS_iS_E = {"Function_2*", drb_free_foreign_object_indirect};
static void *(*drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_FromRuby(mrb_state *state, mrb_value self))(struct mrb_state *, void *, int, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_2Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFPvP9mrb_stateS_iS_E);
    return ((struct drb_foreign_object_ZTSPFPvP9mrb_stateS_iS_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_ToRuby(mrb_state *state, void *(*value)(struct mrb_state *, void *, int, void *)) {
    struct drb_foreign_object_ZTSPFPvP9mrb_stateS_iS_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPvP9mrb_stateS_iS_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_2Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFPvP9mrb_stateS_iS_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP5RProc {
    drb_foreign_object_kind kind;
    struct RProc *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP5RProc = {"RProc*", drb_free_foreign_object_indirect};
static struct RProc *drb_ffi__ZTSP5RProc_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RProcPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP5RProc);
    return ((struct drb_foreign_object_ZTSP5RProc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP5RProc_ToRuby(mrb_state *state, struct RProc *value) {
    struct drb_foreign_object_ZTSP5RProc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP5RProc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RProcPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP5RProc);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP8mrb_pool {
    drb_foreign_object_kind kind;
    struct mrb_pool *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP8mrb_pool = {"mrb_pool*", drb_free_foreign_object_indirect};
static struct mrb_pool *drb_ffi__ZTSP8mrb_pool_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_poolPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP8mrb_pool);
    return ((struct drb_foreign_object_ZTSP8mrb_pool *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP8mrb_pool_ToRuby(mrb_state *state, struct mrb_pool *value) {
    struct drb_foreign_object_ZTSP8mrb_pool *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP8mrb_pool));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_poolPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP8mrb_pool);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvP9mrb_stateE {
    drb_foreign_object_kind kind;
    void (*value)(struct mrb_state *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvP9mrb_stateE = {"Function_3*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvP9mrb_stateE_FromRuby(mrb_state *state, mrb_value self))(struct mrb_state *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_3Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvP9mrb_stateE);
    return ((struct drb_foreign_object_ZTSPFvP9mrb_stateE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvP9mrb_stateE_ToRuby(mrb_state *state, void (*value)(struct mrb_state *)) {
    struct drb_foreign_object_ZTSPFvP9mrb_stateE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP9mrb_stateE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_3Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvP9mrb_stateE);
    return mrb_obj_value(rdata);
}
static char drb_ffi__ZTSc_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSc_ToRuby(mrb_state *state, char value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSP6RFloat {
    drb_foreign_object_kind kind;
    struct RFloat *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP6RFloat = {"RFloat*", drb_free_foreign_object_indirect};
static struct RFloat *drb_ffi__ZTSP6RFloat_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFloatPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP6RFloat);
    return ((struct drb_foreign_object_ZTSP6RFloat *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP6RFloat_ToRuby(mrb_state *state, struct RFloat *value) {
    struct drb_foreign_object_ZTSP6RFloat *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6RFloat));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFloatPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP6RFloat);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP8RInteger {
    drb_foreign_object_kind kind;
    struct RInteger *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP8RInteger = {"RInteger*", drb_free_foreign_object_indirect};
static struct RInteger *drb_ffi__ZTSP8RInteger_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RIntegerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP8RInteger);
    return ((struct drb_foreign_object_ZTSP8RInteger *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP8RInteger_ToRuby(mrb_state *state, struct RInteger *value) {
    struct drb_foreign_object_ZTSP8RInteger *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP8RInteger));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RIntegerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP8RInteger);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP5RCptr {
    drb_foreign_object_kind kind;
    struct RCptr *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP5RCptr = {"RCptr*", drb_free_foreign_object_indirect};
static struct RCptr *drb_ffi__ZTSP5RCptr_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RCptrPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP5RCptr);
    return ((struct drb_foreign_object_ZTSP5RCptr *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP5RCptr_ToRuby(mrb_state *state, struct RCptr *value) {
    struct drb_foreign_object_ZTSP5RCptr *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP5RCptr));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RCptrPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP5RCptr);
    return mrb_obj_value(rdata);
}
static uintptr_t drb_ffi__ZTSj_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSj_ToRuby(mrb_state *state, uintptr_t value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTS9mrb_state {
    drb_foreign_object_kind kind;
    struct mrb_state value;
};
static mrb_data_type ForeignObjectType_ZTS9mrb_state = {"mrb_state", drb_free_foreign_object_indirect};
static struct mrb_state drb_ffi__ZTS9mrb_state_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_state");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS9mrb_state);
    return ((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS9mrb_state_ToRuby(mrb_state *state, struct mrb_state value) {
    struct drb_foreign_object_ZTS9mrb_state *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS9mrb_state));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_state");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS9mrb_state);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS11mrb_context {
    drb_foreign_object_kind kind;
    struct mrb_context value;
};
static mrb_data_type ForeignObjectType_ZTS11mrb_context = {"mrb_context", drb_free_foreign_object_indirect};
static struct mrb_context drb_ffi__ZTS11mrb_context_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_context");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS11mrb_context);
    return ((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS11mrb_context_ToRuby(mrb_state *state, struct mrb_context value) {
    struct drb_foreign_object_ZTS11mrb_context *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS11mrb_context));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_context");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS11mrb_context);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS6RBasic {
    drb_foreign_object_kind kind;
    struct RBasic value;
};
static mrb_data_type ForeignObjectType_ZTS6RBasic = {"RBasic", drb_free_foreign_object_indirect};
static struct RBasic drb_ffi__ZTS6RBasic_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RBasic");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS6RBasic);
    return ((struct drb_foreign_object_ZTS6RBasic *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS6RBasic_ToRuby(mrb_state *state, struct RBasic value) {
    struct drb_foreign_object_ZTS6RBasic *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6RBasic));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RBasic");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS6RBasic);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS7RObject {
    drb_foreign_object_kind kind;
    struct RObject value;
};
static mrb_data_type ForeignObjectType_ZTS7RObject = {"RObject", drb_free_foreign_object_indirect};
static struct RObject drb_ffi__ZTS7RObject_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RObject");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS7RObject);
    return ((struct drb_foreign_object_ZTS7RObject *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS7RObject_ToRuby(mrb_state *state, struct RObject value) {
    struct drb_foreign_object_ZTS7RObject *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS7RObject));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RObject");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS7RObject);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS6RFloat {
    drb_foreign_object_kind kind;
    struct RFloat value;
};
static mrb_data_type ForeignObjectType_ZTS6RFloat = {"RFloat", drb_free_foreign_object_indirect};
static struct RFloat drb_ffi__ZTS6RFloat_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFloat");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS6RFloat);
    return ((struct drb_foreign_object_ZTS6RFloat *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS6RFloat_ToRuby(mrb_state *state, struct RFloat value) {
    struct drb_foreign_object_ZTS6RFloat *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6RFloat));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFloat");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS6RFloat);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS8RInteger {
    drb_foreign_object_kind kind;
    struct RInteger value;
};
static mrb_data_type ForeignObjectType_ZTS8RInteger = {"RInteger", drb_free_foreign_object_indirect};
static struct RInteger drb_ffi__ZTS8RInteger_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RInteger");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS8RInteger);
    return ((struct drb_foreign_object_ZTS8RInteger *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS8RInteger_ToRuby(mrb_state *state, struct RInteger value) {
    struct drb_foreign_object_ZTS8RInteger *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS8RInteger));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RInteger");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS8RInteger);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS5RCptr {
    drb_foreign_object_kind kind;
    struct RCptr value;
};
static mrb_data_type ForeignObjectType_ZTS5RCptr = {"RCptr", drb_free_foreign_object_indirect};
static struct RCptr drb_ffi__ZTS5RCptr_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RCptr");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS5RCptr);
    return ((struct drb_foreign_object_ZTS5RCptr *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS5RCptr_ToRuby(mrb_state *state, struct RCptr value) {
    struct drb_foreign_object_ZTS5RCptr *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS5RCptr));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RCptr");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS5RCptr);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP10mrb_jmpbuf {
    drb_foreign_object_kind kind;
    struct mrb_jmpbuf *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP10mrb_jmpbuf = {"mrb_jmpbuf*", drb_free_foreign_object_indirect};
static struct mrb_jmpbuf *drb_ffi__ZTSP10mrb_jmpbuf_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_jmpbufPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP10mrb_jmpbuf);
    return ((struct drb_foreign_object_ZTSP10mrb_jmpbuf *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP10mrb_jmpbuf_ToRuby(mrb_state *state, struct mrb_jmpbuf *value) {
    struct drb_foreign_object_ZTSP10mrb_jmpbuf *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP10mrb_jmpbuf));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_jmpbufPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP10mrb_jmpbuf);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP6iv_tbl {
    drb_foreign_object_kind kind;
    struct iv_tbl *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP6iv_tbl = {"iv_tbl*", drb_free_foreign_object_indirect};
static struct iv_tbl *drb_ffi__ZTSP6iv_tbl_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Iv_tblPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP6iv_tbl);
    return ((struct drb_foreign_object_ZTSP6iv_tbl *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP6iv_tbl_ToRuby(mrb_state *state, struct iv_tbl *value) {
    struct drb_foreign_object_ZTSP6iv_tbl *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6iv_tbl));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Iv_tblPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP6iv_tbl);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS6mrb_gc {
    drb_foreign_object_kind kind;
    mrb_gc value;
};
static mrb_data_type ForeignObjectType_ZTS6mrb_gc = {"mrb_gc", drb_free_foreign_object_indirect};
static mrb_gc drb_ffi__ZTS6mrb_gc_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_gc");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS6mrb_gc);
    return ((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS6mrb_gc_ToRuby(mrb_state *state, mrb_gc value) {
    struct drb_foreign_object_ZTS6mrb_gc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6mrb_gc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_gc");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS6mrb_gc);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP11symbol_name {
    drb_foreign_object_kind kind;
    struct symbol_name *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP11symbol_name = {"symbol_name*", drb_free_foreign_object_indirect};
static struct symbol_name *drb_ffi__ZTSP11symbol_name_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Symbol_namePointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP11symbol_name);
    return ((struct drb_foreign_object_ZTSP11symbol_name *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP11symbol_name_ToRuby(mrb_state *state, struct symbol_name *value) {
    struct drb_foreign_object_ZTSP11symbol_name *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP11symbol_name));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Symbol_namePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP11symbol_name);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPPFvP9mrb_stateE {
    drb_foreign_object_kind kind;
    void (**value)(struct mrb_state *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPFvP9mrb_stateE = {"Function_3**", drb_free_foreign_object_indirect};
static void (**drb_ffi__ZTSPPFvP9mrb_stateE_FromRuby(mrb_state *state, mrb_value self))(struct mrb_state *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_3PointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPPFvP9mrb_stateE);
    return ((struct drb_foreign_object_ZTSPPFvP9mrb_stateE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPFvP9mrb_stateE_ToRuby(mrb_state *state, void (**value)(struct mrb_state *)) {
    struct drb_foreign_object_ZTSPPFvP9mrb_stateE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPFvP9mrb_stateE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_3PointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPPFvP9mrb_stateE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP3$_0 {
    drb_foreign_object_kind kind;
    mrb_callinfo *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP3$_0 = {"*", drb_free_foreign_object_indirect};
static mrb_callinfo *drb_ffi__ZTSP3$_0_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP3$_0);
    return ((struct drb_foreign_object_ZTSP3$_0 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP3$_0_ToRuby(mrb_state *state, mrb_callinfo *value) {
    struct drb_foreign_object_ZTSP3$_0 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_0));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP3$_0);
    return mrb_obj_value(rdata);
}
static enum mrb_fiber_state drb_ffi__ZTS15mrb_fiber_state_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTS15mrb_fiber_state_ToRuby(mrb_state *state, enum mrb_fiber_state value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSP6RFiber {
    drb_foreign_object_kind kind;
    struct RFiber *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP6RFiber = {"RFiber*", drb_free_foreign_object_indirect};
static struct RFiber *drb_ffi__ZTSP6RFiber_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFiberPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP6RFiber);
    return ((struct drb_foreign_object_ZTSP6RFiber *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP6RFiber_ToRuby(mrb_state *state, struct RFiber *value) {
    struct drb_foreign_object_ZTSP6RFiber *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6RFiber));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFiberPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP6RFiber);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP13mrb_heap_page {
    drb_foreign_object_kind kind;
    mrb_heap_page *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP13mrb_heap_page = {"mrb_heap_page*", drb_free_foreign_object_indirect};
static mrb_heap_page *drb_ffi__ZTSP13mrb_heap_page_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_heap_pagePointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP13mrb_heap_page);
    return ((struct drb_foreign_object_ZTSP13mrb_heap_page *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP13mrb_heap_page_ToRuby(mrb_state *state, mrb_heap_page *value) {
    struct drb_foreign_object_ZTSP13mrb_heap_page *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP13mrb_heap_page));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_heap_pagePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP13mrb_heap_page);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPP6RBasic {
    drb_foreign_object_kind kind;
    struct RBasic **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPP6RBasic = {"RBasic**", drb_free_foreign_object_indirect};
static struct RBasic **drb_ffi__ZTSPP6RBasic_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RBasicPointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPP6RBasic);
    return ((struct drb_foreign_object_ZTSPP6RBasic *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPP6RBasic_ToRuby(mrb_state *state, struct RBasic **value) {
    struct drb_foreign_object_ZTSPP6RBasic *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP6RBasic));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RBasicPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPP6RBasic);
    return mrb_obj_value(rdata);
}
static mrb_gc_state drb_ffi__ZTS12mrb_gc_state_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTS12mrb_gc_state_ToRuby(mrb_state *state, mrb_gc_state value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTS3$_0 {
    drb_foreign_object_kind kind;
    mrb_callinfo value;
};
static mrb_data_type ForeignObjectType_ZTS3$_0 = {"", drb_free_foreign_object_indirect};
static mrb_callinfo drb_ffi__ZTS3$_0_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS3$_0);
    return ((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS3$_0_ToRuby(mrb_state *state, mrb_callinfo value) {
    struct drb_foreign_object_ZTS3$_0 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS3$_0));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS3$_0);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS6RFiber {
    drb_foreign_object_kind kind;
    struct RFiber value;
};
static mrb_data_type ForeignObjectType_ZTS6RFiber = {"RFiber", drb_free_foreign_object_indirect};
static struct RFiber drb_ffi__ZTS6RFiber_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFiber");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS6RFiber);
    return ((struct drb_foreign_object_ZTS6RFiber *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS6RFiber_ToRuby(mrb_state *state, struct RFiber value) {
    struct drb_foreign_object_ZTS6RFiber *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6RFiber));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFiber");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS6RFiber);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS13mrb_heap_page {
    drb_foreign_object_kind kind;
    mrb_heap_page value;
};
static mrb_data_type ForeignObjectType_ZTS13mrb_heap_page = {"mrb_heap_page", drb_free_foreign_object_indirect};
static mrb_heap_page drb_ffi__ZTS13mrb_heap_page_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_heap_page");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS13mrb_heap_page);
    return ((struct drb_foreign_object_ZTS13mrb_heap_page *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_ToRuby(mrb_state *state, mrb_heap_page value) {
    struct drb_foreign_object_ZTS13mrb_heap_page *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS13mrb_heap_page));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_heap_page");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS13mrb_heap_page);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSN3$_03$_1E {
    drb_foreign_object_kind kind;
    union (anonymous union at ../include/mruby.h:158:3) value;
};
static mrb_data_type ForeignObjectType_ZTSN3$_03$_1E = {"", drb_free_foreign_object_indirect};
static union (anonymous union at ../include/mruby.h:158:3) drb_ffi__ZTSN3$_03$_1E_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSN3$_03$_1E);
    return ((struct drb_foreign_object_ZTSN3$_03$_1E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSN3$_03$_1E_ToRuby(mrb_state *state, union (anonymous union at ../include/mruby.h:158:3) value) {
    struct drb_foreign_object_ZTSN3$_03$_1E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSN3$_03$_1E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSN3$_03$_1E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP4REnv {
    drb_foreign_object_kind kind;
    struct REnv *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP4REnv = {"REnv*", drb_free_foreign_object_indirect};
static struct REnv *drb_ffi__ZTSP4REnv_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "REnvPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP4REnv);
    return ((struct drb_foreign_object_ZTSP4REnv *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP4REnv_ToRuby(mrb_state *state, struct REnv *value) {
    struct drb_foreign_object_ZTSP4REnv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP4REnv));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "REnvPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP4REnv);
    return mrb_obj_value(rdata);
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
static mrb_value drb_ffi__ZTSPPc_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPc));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(char *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "CharPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPPc);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPc_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPc_ToRuby(mrb, *drb_ffi__ZTSPPc_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPc_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPc_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPc_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPc_ToRuby(mrb, drb_ffi__ZTSPPc_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPc_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    char *new_value = drb_ffi__ZTSPc_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPc_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP9mrb_state_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP9mrb_state *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP9mrb_state));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct mrb_state));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Mrb_statePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP9mrb_state);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP9mrb_state_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS9mrb_state_ToRuby(mrb, *drb_ffi__ZTSP9mrb_state_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP9mrb_state_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP9mrb_state_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP9mrb_state_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS9mrb_state_ToRuby(mrb, drb_ffi__ZTSP9mrb_state_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP9mrb_state_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct mrb_state new_value = drb_ffi__ZTS9mrb_state_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP9mrb_state_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP9mrb_stateP6RBasicPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP9mrb_stateP6RBasicPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(mrb_each_object_callback));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_0Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP9mrb_stateP6RBasicPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11mrb_context_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP11mrb_context *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP11mrb_context));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct mrb_context));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Mrb_contextPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP11mrb_context);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP11mrb_context_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS11mrb_context_ToRuby(mrb, *drb_ffi__ZTSP11mrb_context_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP11mrb_context_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP11mrb_context_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP11mrb_context_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS11mrb_context_ToRuby(mrb, drb_ffi__ZTSP11mrb_context_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP11mrb_context_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct mrb_context new_value = drb_ffi__ZTS11mrb_context_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP11mrb_context_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6RBasic_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP6RBasic *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6RBasic));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct RBasic));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "RBasicPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP6RBasic);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP6RBasic_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS6RBasic_ToRuby(mrb, *drb_ffi__ZTSP6RBasic_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP6RBasic_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP6RBasic_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP6RBasic_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS6RBasic_ToRuby(mrb, drb_ffi__ZTSP6RBasic_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP6RBasic_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct RBasic new_value = drb_ffi__ZTS6RBasic_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP6RBasic_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6RClass_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6RClass_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6RClass_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP6RClass_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP6RClass_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6RClass_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPF9mrb_valueP9mrb_stateS_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPF9mrb_valueP9mrb_stateS_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(mrb_value (struct mrb_state *, mrb_value)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_1Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPF9mrb_valueP9mrb_stateS_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP7RObject_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP7RObject *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP7RObject));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct RObject));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "RObjectPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP7RObject);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP7RObject_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS7RObject_ToRuby(mrb, *drb_ffi__ZTSP7RObject_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP7RObject_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP7RObject_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP7RObject_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS7RObject_ToRuby(mrb, drb_ffi__ZTSP7RObject_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP7RObject_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct RObject new_value = drb_ffi__ZTS7RObject_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP7RObject_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP9mrb_value_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP9mrb_value *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP9mrb_value));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(mrb_value));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Mrb_valuePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP9mrb_value);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP9mrb_value_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS9mrb_value_ToRuby(mrb, *drb_ffi__ZTSP9mrb_value_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP9mrb_value_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP9mrb_value_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP9mrb_value_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS9mrb_value_ToRuby(mrb, drb_ffi__ZTSP9mrb_value_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP9mrb_value_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    mrb_value new_value = drb_ffi__ZTS9mrb_value_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP9mrb_value_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFPvP9mrb_stateS_iS_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPvP9mrb_stateS_iS_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void *(struct mrb_state *, void *, int, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_2Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFPvP9mrb_stateS_iS_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP5RProc_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP5RProc_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP5RProc_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP5RProc_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP5RProc_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP5RProc_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP8mrb_pool_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP8mrb_pool_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP8mrb_pool_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP8mrb_pool_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP8mrb_pool_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP8mrb_pool_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP9mrb_stateE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvP9mrb_stateE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP9mrb_stateE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (struct mrb_state *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_3Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvP9mrb_stateE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvP9mrb_stateE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP9mrb_stateE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvP9mrb_stateE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvP9mrb_stateE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP9mrb_stateE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6RFloat_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP6RFloat *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6RFloat));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct RFloat));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "RFloatPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP6RFloat);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP6RFloat_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS6RFloat_ToRuby(mrb, *drb_ffi__ZTSP6RFloat_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP6RFloat_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP6RFloat_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP6RFloat_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS6RFloat_ToRuby(mrb, drb_ffi__ZTSP6RFloat_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP6RFloat_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct RFloat new_value = drb_ffi__ZTS6RFloat_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP6RFloat_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP8RInteger_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP8RInteger *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP8RInteger));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct RInteger));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "RIntegerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP8RInteger);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP8RInteger_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS8RInteger_ToRuby(mrb, *drb_ffi__ZTSP8RInteger_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP8RInteger_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP8RInteger_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP8RInteger_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS8RInteger_ToRuby(mrb, drb_ffi__ZTSP8RInteger_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP8RInteger_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct RInteger new_value = drb_ffi__ZTS8RInteger_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP8RInteger_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP5RCptr_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP5RCptr *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP5RCptr));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct RCptr));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "RCptrPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP5RCptr);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP5RCptr_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS5RCptr_ToRuby(mrb, *drb_ffi__ZTSP5RCptr_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP5RCptr_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP5RCptr_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP5RCptr_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS5RCptr_ToRuby(mrb, drb_ffi__ZTSP5RCptr_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP5RCptr_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct RCptr new_value = drb_ffi__ZTS5RCptr_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP5RCptr_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP10mrb_jmpbuf_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP10mrb_jmpbuf_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP10mrb_jmpbuf_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP10mrb_jmpbuf_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP10mrb_jmpbuf_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP10mrb_jmpbuf_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6iv_tbl_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6iv_tbl_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6iv_tbl_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP6iv_tbl_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP6iv_tbl_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6iv_tbl_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11symbol_name_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11symbol_name_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11symbol_name_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP11symbol_name_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP11symbol_name_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11symbol_name_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPPFvP9mrb_stateE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPFvP9mrb_stateE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPFvP9mrb_stateE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (*)(struct mrb_state *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_3PointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPPFvP9mrb_stateE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPFvP9mrb_stateE_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPFvP9mrb_stateE_ToRuby(mrb, *drb_ffi__ZTSPPFvP9mrb_stateE_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPFvP9mrb_stateE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPFvP9mrb_stateE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPFvP9mrb_stateE_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPFvP9mrb_stateE_ToRuby(mrb, drb_ffi__ZTSPPFvP9mrb_stateE_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPFvP9mrb_stateE_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    void (*new_value)(struct mrb_state *) = drb_ffi__ZTSPFvP9mrb_stateE_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPFvP9mrb_stateE_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP3$_0_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP3$_0 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP3$_0));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(mrb_callinfo));
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
    mrb_callinfo new_value = drb_ffi__ZTS3$_0_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP3$_0_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP6RFiber_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP6RFiber *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP6RFiber));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct RFiber));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "RFiberPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP6RFiber);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP6RFiber_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS6RFiber_ToRuby(mrb, *drb_ffi__ZTSP6RFiber_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP6RFiber_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP6RFiber_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP6RFiber_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS6RFiber_ToRuby(mrb, drb_ffi__ZTSP6RFiber_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP6RFiber_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct RFiber new_value = drb_ffi__ZTS6RFiber_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP6RFiber_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13mrb_heap_page_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP13mrb_heap_page *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP13mrb_heap_page));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(mrb_heap_page));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Mrb_heap_pagePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP13mrb_heap_page);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP13mrb_heap_page_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS13mrb_heap_page_ToRuby(mrb, *drb_ffi__ZTSP13mrb_heap_page_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP13mrb_heap_page_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP13mrb_heap_page_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP13mrb_heap_page_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS13mrb_heap_page_ToRuby(mrb, drb_ffi__ZTSP13mrb_heap_page_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP13mrb_heap_page_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    mrb_heap_page new_value = drb_ffi__ZTS13mrb_heap_page_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP13mrb_heap_page_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPP6RBasic_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPP6RBasic *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP6RBasic));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct RBasic *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "RBasicPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPP6RBasic);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPP6RBasic_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSP6RBasic_ToRuby(mrb, *drb_ffi__ZTSPP6RBasic_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPP6RBasic_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPP6RBasic_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPP6RBasic_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSP6RBasic_ToRuby(mrb, drb_ffi__ZTSPP6RBasic_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPP6RBasic_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPP6RBasic_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP4REnv_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP4REnv_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP4REnv_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP4REnv_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP4REnv_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP4REnv_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS10mrb_value__New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS10mrb_value_ *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS10mrb_value_ *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_value_");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS10mrb_value_);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS10mrb_value__p_Get(mrb_state *state, mrb_value self) {
    union mrb_value_ record = drb_ffi__ZTS10mrb_value__FromRuby(state, self);
    return drb_ffi__ZTSPv_ToRuby(state, record.p);
}
static mrb_value drb_ffi__ZTS10mrb_value__p_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void *new_value = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS10mrb_value_ *)DATA_PTR(self))->value)->p = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS10mrb_value__bp_Get(mrb_state *state, mrb_value self) {
    union mrb_value_ record = drb_ffi__ZTS10mrb_value__FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.bp);
}
static mrb_value drb_ffi__ZTS10mrb_value__bp_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS10mrb_value_ *)DATA_PTR(self))->value)->bp = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS10mrb_value__fp_Get(mrb_state *state, mrb_value self) {
    union mrb_value_ record = drb_ffi__ZTS10mrb_value__FromRuby(state, self);
    return drb_ffi__ZTSP6RFloat_ToRuby(state, record.fp);
}
static mrb_value drb_ffi__ZTS10mrb_value__fp_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RFloat *new_value = drb_ffi__ZTSP6RFloat_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS10mrb_value_ *)DATA_PTR(self))->value)->fp = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS10mrb_value__ip_Get(mrb_state *state, mrb_value self) {
    union mrb_value_ record = drb_ffi__ZTS10mrb_value__FromRuby(state, self);
    return drb_ffi__ZTSP8RInteger_ToRuby(state, record.ip);
}
static mrb_value drb_ffi__ZTS10mrb_value__ip_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RInteger *new_value = drb_ffi__ZTSP8RInteger_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS10mrb_value_ *)DATA_PTR(self))->value)->ip = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS10mrb_value__vp_Get(mrb_state *state, mrb_value self) {
    union mrb_value_ record = drb_ffi__ZTS10mrb_value__FromRuby(state, self);
    return drb_ffi__ZTSP5RCptr_ToRuby(state, record.vp);
}
static mrb_value drb_ffi__ZTS10mrb_value__vp_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RCptr *new_value = drb_ffi__ZTSP5RCptr_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS10mrb_value_ *)DATA_PTR(self))->value)->vp = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS10mrb_value__w_Get(mrb_state *state, mrb_value self) {
    union mrb_value_ record = drb_ffi__ZTS10mrb_value__FromRuby(state, self);
    return drb_ffi__ZTSj_ToRuby(state, record.w);
}
static mrb_value drb_ffi__ZTS10mrb_value__w_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uintptr_t new_value = drb_ffi__ZTSj_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS10mrb_value_ *)DATA_PTR(self))->value)->w = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS10mrb_value__value_Get(mrb_state *state, mrb_value self) {
    union mrb_value_ record = drb_ffi__ZTS10mrb_value__FromRuby(state, self);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, record.value);
}
static mrb_value drb_ffi__ZTS10mrb_value__value_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_value new_value = drb_ffi__ZTS9mrb_value_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS10mrb_value_ *)DATA_PTR(self))->value)->value = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_value_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS9mrb_value *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS9mrb_value *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_value");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS9mrb_value);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS9mrb_value_w_Get(mrb_state *state, mrb_value self) {
    mrb_value record = drb_ffi__ZTS9mrb_value_FromRuby(state, self);
    return drb_ffi__ZTSj_ToRuby(state, record.w);
}
static mrb_value drb_ffi__ZTS9mrb_value_w_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uintptr_t new_value = drb_ffi__ZTSj_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_value *)DATA_PTR(self))->value)->w = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS9mrb_state *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS9mrb_state *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_state");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS9mrb_state);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS9mrb_state_jmp_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP10mrb_jmpbuf_ToRuby(state, record.jmp);
}
static mrb_value drb_ffi__ZTS9mrb_state_jmp_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_jmpbuf *new_value = drb_ffi__ZTSP10mrb_jmpbuf_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->jmp = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_allocf_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_ToRuby(state, record.allocf);
}
static mrb_value drb_ffi__ZTS9mrb_state_allocf_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void *(*new_value)(struct mrb_state *, void *, int, void *) = drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->allocf = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_allocf_ud_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSPv_ToRuby(state, record.allocf_ud);
}
static mrb_value drb_ffi__ZTS9mrb_state_allocf_ud_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void *new_value = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->allocf_ud = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_c_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP11mrb_context_ToRuby(state, record.c);
}
static mrb_value drb_ffi__ZTS9mrb_state_c_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_context *new_value = drb_ffi__ZTSP11mrb_context_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->c = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_root_c_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP11mrb_context_ToRuby(state, record.root_c);
}
static mrb_value drb_ffi__ZTS9mrb_state_root_c_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_context *new_value = drb_ffi__ZTSP11mrb_context_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->root_c = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_globals_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6iv_tbl_ToRuby(state, record.globals);
}
static mrb_value drb_ffi__ZTS9mrb_state_globals_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct iv_tbl *new_value = drb_ffi__ZTSP6iv_tbl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->globals = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_exc_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP7RObject_ToRuby(state, record.exc);
}
static mrb_value drb_ffi__ZTS9mrb_state_exc_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RObject *new_value = drb_ffi__ZTSP7RObject_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->exc = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_top_self_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP7RObject_ToRuby(state, record.top_self);
}
static mrb_value drb_ffi__ZTS9mrb_state_top_self_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RObject *new_value = drb_ffi__ZTSP7RObject_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->top_self = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_object_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.object_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_object_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->object_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_class_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.class_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_class_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->class_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_module_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.module_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_module_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->module_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_proc_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.proc_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_proc_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->proc_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_string_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.string_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_string_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->string_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_array_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.array_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_array_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->array_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_hash_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.hash_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_hash_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->hash_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_range_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.range_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_range_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->range_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_float_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.float_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_float_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->float_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_integer_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.integer_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_integer_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->integer_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_true_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.true_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_true_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->true_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_false_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.false_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_false_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->false_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_nil_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.nil_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_nil_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->nil_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_symbol_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.symbol_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_symbol_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->symbol_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_kernel_module_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.kernel_module);
}
static mrb_value drb_ffi__ZTS9mrb_state_kernel_module_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->kernel_module = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_gc_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTS6mrb_gc_ToRuby(state, record.gc);
}
static mrb_value drb_ffi__ZTS9mrb_state_gc_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_gc new_value = drb_ffi__ZTS6mrb_gc_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->gc = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_cache_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_cache_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_symidx_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.symidx);
}
static mrb_value drb_ffi__ZTS9mrb_state_symidx_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->symidx = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_symtbl_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP11symbol_name_ToRuby(state, record.symtbl);
}
static mrb_value drb_ffi__ZTS9mrb_state_symtbl_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct symbol_name *new_value = drb_ffi__ZTSP11symbol_name_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->symtbl = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_symhash_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_symhash_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_symcapa_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.symcapa);
}
static mrb_value drb_ffi__ZTS9mrb_state_symcapa_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->symcapa = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_sym_default_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.sym_default);
}
static mrb_value drb_ffi__ZTS9mrb_state_sym_default_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->sym_default = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_sym_initialize_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.sym_initialize);
}
static mrb_value drb_ffi__ZTS9mrb_state_sym_initialize_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->sym_initialize = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_symbuf_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_symbuf_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set constant array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_eException_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.eException_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_eException_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->eException_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_eStandardError_class_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.eStandardError_class);
}
static mrb_value drb_ffi__ZTS9mrb_state_eStandardError_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->eStandardError_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_nomem_err_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP7RObject_ToRuby(state, record.nomem_err);
}
static mrb_value drb_ffi__ZTS9mrb_state_nomem_err_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RObject *new_value = drb_ffi__ZTSP7RObject_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->nomem_err = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_stack_err_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSP7RObject_ToRuby(state, record.stack_err);
}
static mrb_value drb_ffi__ZTS9mrb_state_stack_err_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RObject *new_value = drb_ffi__ZTSP7RObject_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->stack_err = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_ud_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSPv_ToRuby(state, record.ud);
}
static mrb_value drb_ffi__ZTS9mrb_state_ud_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void *new_value = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->ud = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_atexit_stack_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSPPFvP9mrb_stateE_ToRuby(state, record.atexit_stack);
}
static mrb_value drb_ffi__ZTS9mrb_state_atexit_stack_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void (**new_value)(struct mrb_state *) = drb_ffi__ZTSPPFvP9mrb_stateE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->atexit_stack = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS9mrb_state_atexit_stack_len_Get(mrb_state *state, mrb_value self) {
    struct mrb_state record = drb_ffi__ZTS9mrb_state_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.atexit_stack_len);
}
static mrb_value drb_ffi__ZTS9mrb_state_atexit_stack_len_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS9mrb_state *)DATA_PTR(self))->value)->atexit_stack_len = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS11mrb_context *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS11mrb_context *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_context");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS11mrb_context);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS11mrb_context_prev_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTSP11mrb_context_ToRuby(state, record.prev);
}
static mrb_value drb_ffi__ZTS11mrb_context_prev_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_context *new_value = drb_ffi__ZTSP11mrb_context_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->prev = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_stbase_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTSP9mrb_value_ToRuby(state, record.stbase);
}
static mrb_value drb_ffi__ZTS11mrb_context_stbase_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_value *new_value = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->stbase = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_stend_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTSP9mrb_value_ToRuby(state, record.stend);
}
static mrb_value drb_ffi__ZTS11mrb_context_stend_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_value *new_value = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->stend = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_ci_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTSP3$_0_ToRuby(state, record.ci);
}
static mrb_value drb_ffi__ZTS11mrb_context_ci_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_callinfo *new_value = drb_ffi__ZTSP3$_0_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->ci = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_cibase_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTSP3$_0_ToRuby(state, record.cibase);
}
static mrb_value drb_ffi__ZTS11mrb_context_cibase_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_callinfo *new_value = drb_ffi__ZTSP3$_0_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->cibase = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_ciend_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTSP3$_0_ToRuby(state, record.ciend);
}
static mrb_value drb_ffi__ZTS11mrb_context_ciend_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_callinfo *new_value = drb_ffi__ZTSP3$_0_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->ciend = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_status_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTS15mrb_fiber_state_ToRuby(state, record.status);
}
static mrb_value drb_ffi__ZTS11mrb_context_status_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    enum mrb_fiber_state new_value = drb_ffi__ZTS15mrb_fiber_state_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->status = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_vmexec_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.vmexec);
}
static mrb_value drb_ffi__ZTS11mrb_context_vmexec_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_bool new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->vmexec = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11mrb_context_fib_Get(mrb_state *state, mrb_value self) {
    struct mrb_context record = drb_ffi__ZTS11mrb_context_FromRuby(state, self);
    return drb_ffi__ZTSP6RFiber_ToRuby(state, record.fib);
}
static mrb_value drb_ffi__ZTS11mrb_context_fib_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RFiber *new_value = drb_ffi__ZTSP6RFiber_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11mrb_context *)DATA_PTR(self))->value)->fib = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RBasic_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS6RBasic *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6RBasic *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RBasic");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS6RBasic);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS6RBasic_c_Get(mrb_state *state, mrb_value self) {
    struct RBasic record = drb_ffi__ZTS6RBasic_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.c);
}
static mrb_value drb_ffi__ZTS6RBasic_c_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RBasic *)DATA_PTR(self))->value)->c = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RBasic_gcnext_Get(mrb_state *state, mrb_value self) {
    struct RBasic record = drb_ffi__ZTS6RBasic_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.gcnext);
}
static mrb_value drb_ffi__ZTS6RBasic_gcnext_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RBasic *)DATA_PTR(self))->value)->gcnext = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RBasic_tt_Get(mrb_state *state, mrb_value self) {
    struct RBasic record = drb_ffi__ZTS6RBasic_FromRuby(state, self);
    return drb_ffi__ZTS9mrb_vtype_ToRuby(state, record.tt);
}
static mrb_value drb_ffi__ZTS6RBasic_tt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    enum mrb_vtype new_value = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RBasic *)DATA_PTR(self))->value)->tt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RBasic_color_Get(mrb_state *state, mrb_value self) {
    struct RBasic record = drb_ffi__ZTS6RBasic_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.color);
}
static mrb_value drb_ffi__ZTS6RBasic_color_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RBasic *)DATA_PTR(self))->value)->color = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RBasic_flags_Get(mrb_state *state, mrb_value self) {
    struct RBasic record = drb_ffi__ZTS6RBasic_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.flags);
}
static mrb_value drb_ffi__ZTS6RBasic_flags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RBasic *)DATA_PTR(self))->value)->flags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7RObject_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS7RObject *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS7RObject *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RObject");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS7RObject);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS7RObject_c_Get(mrb_state *state, mrb_value self) {
    struct RObject record = drb_ffi__ZTS7RObject_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.c);
}
static mrb_value drb_ffi__ZTS7RObject_c_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7RObject *)DATA_PTR(self))->value)->c = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7RObject_gcnext_Get(mrb_state *state, mrb_value self) {
    struct RObject record = drb_ffi__ZTS7RObject_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.gcnext);
}
static mrb_value drb_ffi__ZTS7RObject_gcnext_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7RObject *)DATA_PTR(self))->value)->gcnext = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7RObject_tt_Get(mrb_state *state, mrb_value self) {
    struct RObject record = drb_ffi__ZTS7RObject_FromRuby(state, self);
    return drb_ffi__ZTS9mrb_vtype_ToRuby(state, record.tt);
}
static mrb_value drb_ffi__ZTS7RObject_tt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    enum mrb_vtype new_value = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7RObject *)DATA_PTR(self))->value)->tt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7RObject_color_Get(mrb_state *state, mrb_value self) {
    struct RObject record = drb_ffi__ZTS7RObject_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.color);
}
static mrb_value drb_ffi__ZTS7RObject_color_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7RObject *)DATA_PTR(self))->value)->color = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7RObject_flags_Get(mrb_state *state, mrb_value self) {
    struct RObject record = drb_ffi__ZTS7RObject_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.flags);
}
static mrb_value drb_ffi__ZTS7RObject_flags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7RObject *)DATA_PTR(self))->value)->flags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS7RObject_iv_Get(mrb_state *state, mrb_value self) {
    struct RObject record = drb_ffi__ZTS7RObject_FromRuby(state, self);
    return drb_ffi__ZTSP6iv_tbl_ToRuby(state, record.iv);
}
static mrb_value drb_ffi__ZTS7RObject_iv_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct iv_tbl *new_value = drb_ffi__ZTSP6iv_tbl_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS7RObject *)DATA_PTR(self))->value)->iv = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFloat_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS6RFloat *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6RFloat *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFloat");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS6RFloat);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS6RFloat_c_Get(mrb_state *state, mrb_value self) {
    struct RFloat record = drb_ffi__ZTS6RFloat_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.c);
}
static mrb_value drb_ffi__ZTS6RFloat_c_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFloat *)DATA_PTR(self))->value)->c = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFloat_gcnext_Get(mrb_state *state, mrb_value self) {
    struct RFloat record = drb_ffi__ZTS6RFloat_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.gcnext);
}
static mrb_value drb_ffi__ZTS6RFloat_gcnext_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFloat *)DATA_PTR(self))->value)->gcnext = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFloat_tt_Get(mrb_state *state, mrb_value self) {
    struct RFloat record = drb_ffi__ZTS6RFloat_FromRuby(state, self);
    return drb_ffi__ZTS9mrb_vtype_ToRuby(state, record.tt);
}
static mrb_value drb_ffi__ZTS6RFloat_tt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    enum mrb_vtype new_value = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFloat *)DATA_PTR(self))->value)->tt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFloat_color_Get(mrb_state *state, mrb_value self) {
    struct RFloat record = drb_ffi__ZTS6RFloat_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.color);
}
static mrb_value drb_ffi__ZTS6RFloat_color_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFloat *)DATA_PTR(self))->value)->color = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFloat_flags_Get(mrb_state *state, mrb_value self) {
    struct RFloat record = drb_ffi__ZTS6RFloat_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.flags);
}
static mrb_value drb_ffi__ZTS6RFloat_flags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFloat *)DATA_PTR(self))->value)->flags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFloat_f_Get(mrb_state *state, mrb_value self) {
    struct RFloat record = drb_ffi__ZTS6RFloat_FromRuby(state, self);
    return drb_ffi__ZTSd_ToRuby(state, record.f);
}
static mrb_value drb_ffi__ZTS6RFloat_f_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_float new_value = drb_ffi__ZTSd_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFloat *)DATA_PTR(self))->value)->f = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8RInteger_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS8RInteger *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS8RInteger *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RInteger");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS8RInteger);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS8RInteger_c_Get(mrb_state *state, mrb_value self) {
    struct RInteger record = drb_ffi__ZTS8RInteger_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.c);
}
static mrb_value drb_ffi__ZTS8RInteger_c_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8RInteger *)DATA_PTR(self))->value)->c = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8RInteger_gcnext_Get(mrb_state *state, mrb_value self) {
    struct RInteger record = drb_ffi__ZTS8RInteger_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.gcnext);
}
static mrb_value drb_ffi__ZTS8RInteger_gcnext_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8RInteger *)DATA_PTR(self))->value)->gcnext = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8RInteger_tt_Get(mrb_state *state, mrb_value self) {
    struct RInteger record = drb_ffi__ZTS8RInteger_FromRuby(state, self);
    return drb_ffi__ZTS9mrb_vtype_ToRuby(state, record.tt);
}
static mrb_value drb_ffi__ZTS8RInteger_tt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    enum mrb_vtype new_value = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8RInteger *)DATA_PTR(self))->value)->tt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8RInteger_color_Get(mrb_state *state, mrb_value self) {
    struct RInteger record = drb_ffi__ZTS8RInteger_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.color);
}
static mrb_value drb_ffi__ZTS8RInteger_color_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8RInteger *)DATA_PTR(self))->value)->color = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8RInteger_flags_Get(mrb_state *state, mrb_value self) {
    struct RInteger record = drb_ffi__ZTS8RInteger_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.flags);
}
static mrb_value drb_ffi__ZTS8RInteger_flags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8RInteger *)DATA_PTR(self))->value)->flags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS8RInteger_i_Get(mrb_state *state, mrb_value self) {
    struct RInteger record = drb_ffi__ZTS8RInteger_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.i);
}
static mrb_value drb_ffi__ZTS8RInteger_i_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS8RInteger *)DATA_PTR(self))->value)->i = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS5RCptr_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS5RCptr *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS5RCptr *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RCptr");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS5RCptr);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS5RCptr_c_Get(mrb_state *state, mrb_value self) {
    struct RCptr record = drb_ffi__ZTS5RCptr_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.c);
}
static mrb_value drb_ffi__ZTS5RCptr_c_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS5RCptr *)DATA_PTR(self))->value)->c = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS5RCptr_gcnext_Get(mrb_state *state, mrb_value self) {
    struct RCptr record = drb_ffi__ZTS5RCptr_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.gcnext);
}
static mrb_value drb_ffi__ZTS5RCptr_gcnext_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS5RCptr *)DATA_PTR(self))->value)->gcnext = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS5RCptr_tt_Get(mrb_state *state, mrb_value self) {
    struct RCptr record = drb_ffi__ZTS5RCptr_FromRuby(state, self);
    return drb_ffi__ZTS9mrb_vtype_ToRuby(state, record.tt);
}
static mrb_value drb_ffi__ZTS5RCptr_tt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    enum mrb_vtype new_value = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS5RCptr *)DATA_PTR(self))->value)->tt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS5RCptr_color_Get(mrb_state *state, mrb_value self) {
    struct RCptr record = drb_ffi__ZTS5RCptr_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.color);
}
static mrb_value drb_ffi__ZTS5RCptr_color_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS5RCptr *)DATA_PTR(self))->value)->color = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS5RCptr_flags_Get(mrb_state *state, mrb_value self) {
    struct RCptr record = drb_ffi__ZTS5RCptr_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.flags);
}
static mrb_value drb_ffi__ZTS5RCptr_flags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS5RCptr *)DATA_PTR(self))->value)->flags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS5RCptr_p_Get(mrb_state *state, mrb_value self) {
    struct RCptr record = drb_ffi__ZTS5RCptr_FromRuby(state, self);
    return drb_ffi__ZTSPv_ToRuby(state, record.p);
}
static mrb_value drb_ffi__ZTS5RCptr_p_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void *new_value = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS5RCptr *)DATA_PTR(self))->value)->p = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS6mrb_gc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6mrb_gc *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_gc");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS6mrb_gc);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS6mrb_gc_heaps_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSP13mrb_heap_page_ToRuby(state, record.heaps);
}
static mrb_value drb_ffi__ZTS6mrb_gc_heaps_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_heap_page *new_value = drb_ffi__ZTSP13mrb_heap_page_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->heaps = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_sweeps_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSP13mrb_heap_page_ToRuby(state, record.sweeps);
}
static mrb_value drb_ffi__ZTS6mrb_gc_sweeps_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_heap_page *new_value = drb_ffi__ZTSP13mrb_heap_page_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->sweeps = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_free_heaps_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSP13mrb_heap_page_ToRuby(state, record.free_heaps);
}
static mrb_value drb_ffi__ZTS6mrb_gc_free_heaps_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_heap_page *new_value = drb_ffi__ZTSP13mrb_heap_page_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->free_heaps = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_live_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.live);
}
static mrb_value drb_ffi__ZTS6mrb_gc_live_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->live = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_arena_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSPP6RBasic_ToRuby(state, record.arena);
}
static mrb_value drb_ffi__ZTS6mrb_gc_arena_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic **new_value = drb_ffi__ZTSPP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->arena = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_arena_capa_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.arena_capa);
}
static mrb_value drb_ffi__ZTS6mrb_gc_arena_capa_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->arena_capa = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_arena_idx_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.arena_idx);
}
static mrb_value drb_ffi__ZTS6mrb_gc_arena_idx_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->arena_idx = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_state_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTS12mrb_gc_state_ToRuby(state, record.state);
}
static mrb_value drb_ffi__ZTS6mrb_gc_state_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_gc_state new_value = drb_ffi__ZTS12mrb_gc_state_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->state = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_current_white_part_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.current_white_part);
}
static mrb_value drb_ffi__ZTS6mrb_gc_current_white_part_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->current_white_part = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_gray_list_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.gray_list);
}
static mrb_value drb_ffi__ZTS6mrb_gc_gray_list_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->gray_list = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_atomic_gray_list_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.atomic_gray_list);
}
static mrb_value drb_ffi__ZTS6mrb_gc_atomic_gray_list_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->atomic_gray_list = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_live_after_mark_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.live_after_mark);
}
static mrb_value drb_ffi__ZTS6mrb_gc_live_after_mark_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->live_after_mark = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_threshold_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.threshold);
}
static mrb_value drb_ffi__ZTS6mrb_gc_threshold_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->threshold = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_interval_ratio_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.interval_ratio);
}
static mrb_value drb_ffi__ZTS6mrb_gc_interval_ratio_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->interval_ratio = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_step_ratio_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.step_ratio);
}
static mrb_value drb_ffi__ZTS6mrb_gc_step_ratio_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->step_ratio = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_iterating_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.iterating);
}
static mrb_value drb_ffi__ZTS6mrb_gc_iterating_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_bool new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->iterating = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_disabled_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.disabled);
}
static mrb_value drb_ffi__ZTS6mrb_gc_disabled_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_bool new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->disabled = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_full_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.full);
}
static mrb_value drb_ffi__ZTS6mrb_gc_full_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_bool new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->full = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_generational_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.generational);
}
static mrb_value drb_ffi__ZTS6mrb_gc_generational_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_bool new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->generational = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_out_of_memory_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.out_of_memory);
}
static mrb_value drb_ffi__ZTS6mrb_gc_out_of_memory_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_bool new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->out_of_memory = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6mrb_gc_majorgc_old_threshold_Get(mrb_state *state, mrb_value self) {
    mrb_gc record = drb_ffi__ZTS6mrb_gc_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.majorgc_old_threshold);
}
static mrb_value drb_ffi__ZTS6mrb_gc_majorgc_old_threshold_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6mrb_gc *)DATA_PTR(self))->value)->majorgc_old_threshold = new_value;
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
static mrb_value drb_ffi__ZTS3$_0_mid_Get(mrb_state *state, mrb_value self) {
    mrb_callinfo record = drb_ffi__ZTS3$_0_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.mid);
}
static mrb_value drb_ffi__ZTS3$_0_mid_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value)->mid = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0_argc_Get(mrb_state *state, mrb_value self) {
    mrb_callinfo record = drb_ffi__ZTS3$_0_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.argc);
}
static mrb_value drb_ffi__ZTS3$_0_argc_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value)->argc = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0_acc_Get(mrb_state *state, mrb_value self) {
    mrb_callinfo record = drb_ffi__ZTS3$_0_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.acc);
}
static mrb_value drb_ffi__ZTS3$_0_acc_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value)->acc = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0_proc_Get(mrb_state *state, mrb_value self) {
    mrb_callinfo record = drb_ffi__ZTS3$_0_FromRuby(state, self);
    return drb_ffi__ZTSP5RProc_ToRuby(state, record.proc);
}
static mrb_value drb_ffi__ZTS3$_0_proc_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RProc *new_value = drb_ffi__ZTSP5RProc_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value)->proc = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0_stack_Get(mrb_state *state, mrb_value self) {
    mrb_callinfo record = drb_ffi__ZTS3$_0_FromRuby(state, self);
    return drb_ffi__ZTSP9mrb_value_ToRuby(state, record.stack);
}
static mrb_value drb_ffi__ZTS3$_0_stack_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_value *new_value = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value)->stack = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0_pc_Get(mrb_state *state, mrb_value self) {
    mrb_callinfo record = drb_ffi__ZTS3$_0_FromRuby(state, self);
    return drb_ffi__ZTSPi_ToRuby(state, record.pc);
}
static mrb_value drb_ffi__ZTS3$_0_pc_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_code *new_value = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value)->pc = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS3$_0_u_Get(mrb_state *state, mrb_value self) {
    mrb_callinfo record = drb_ffi__ZTS3$_0_FromRuby(state, self);
    return drb_ffi__ZTSN3$_03$_1E_ToRuby(state, record.u);
}
static mrb_value drb_ffi__ZTS3$_0_u_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    union (anonymous union at ../include/mruby.h:158:3) new_value = drb_ffi__ZTSN3$_03$_1E_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS3$_0 *)DATA_PTR(self))->value)->u = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFiber_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS6RFiber *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS6RFiber *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "RFiber");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS6RFiber);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS6RFiber_c_Get(mrb_state *state, mrb_value self) {
    struct RFiber record = drb_ffi__ZTS6RFiber_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.c);
}
static mrb_value drb_ffi__ZTS6RFiber_c_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFiber *)DATA_PTR(self))->value)->c = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFiber_gcnext_Get(mrb_state *state, mrb_value self) {
    struct RFiber record = drb_ffi__ZTS6RFiber_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.gcnext);
}
static mrb_value drb_ffi__ZTS6RFiber_gcnext_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFiber *)DATA_PTR(self))->value)->gcnext = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFiber_tt_Get(mrb_state *state, mrb_value self) {
    struct RFiber record = drb_ffi__ZTS6RFiber_FromRuby(state, self);
    return drb_ffi__ZTS9mrb_vtype_ToRuby(state, record.tt);
}
static mrb_value drb_ffi__ZTS6RFiber_tt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    enum mrb_vtype new_value = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFiber *)DATA_PTR(self))->value)->tt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFiber_color_Get(mrb_state *state, mrb_value self) {
    struct RFiber record = drb_ffi__ZTS6RFiber_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.color);
}
static mrb_value drb_ffi__ZTS6RFiber_color_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFiber *)DATA_PTR(self))->value)->color = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFiber_flags_Get(mrb_state *state, mrb_value self) {
    struct RFiber record = drb_ffi__ZTS6RFiber_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.flags);
}
static mrb_value drb_ffi__ZTS6RFiber_flags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    uint32_t new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFiber *)DATA_PTR(self))->value)->flags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS6RFiber_cxt_Get(mrb_state *state, mrb_value self) {
    struct RFiber record = drb_ffi__ZTS6RFiber_FromRuby(state, self);
    return drb_ffi__ZTSP11mrb_context_ToRuby(state, record.cxt);
}
static mrb_value drb_ffi__ZTS6RFiber_cxt_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_context *new_value = drb_ffi__ZTSP11mrb_context_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS6RFiber *)DATA_PTR(self))->value)->cxt = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS13mrb_heap_page *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS13mrb_heap_page *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Mrb_heap_page");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS13mrb_heap_page);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_freelist_Get(mrb_state *state, mrb_value self) {
    mrb_heap_page record = drb_ffi__ZTS13mrb_heap_page_FromRuby(state, self);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, record.freelist);
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_freelist_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RBasic *new_value = drb_ffi__ZTSP6RBasic_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS13mrb_heap_page *)DATA_PTR(self))->value)->freelist = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_prev_Get(mrb_state *state, mrb_value self) {
    mrb_heap_page record = drb_ffi__ZTS13mrb_heap_page_FromRuby(state, self);
    return drb_ffi__ZTSP13mrb_heap_page_ToRuby(state, record.prev);
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_prev_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_heap_page *new_value = drb_ffi__ZTSP13mrb_heap_page_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS13mrb_heap_page *)DATA_PTR(self))->value)->prev = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_next_Get(mrb_state *state, mrb_value self) {
    mrb_heap_page record = drb_ffi__ZTS13mrb_heap_page_FromRuby(state, self);
    return drb_ffi__ZTSP13mrb_heap_page_ToRuby(state, record.next);
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_next_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_heap_page *new_value = drb_ffi__ZTSP13mrb_heap_page_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS13mrb_heap_page *)DATA_PTR(self))->value)->next = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_free_next_Get(mrb_state *state, mrb_value self) {
    mrb_heap_page record = drb_ffi__ZTS13mrb_heap_page_FromRuby(state, self);
    return drb_ffi__ZTSP13mrb_heap_page_ToRuby(state, record.free_next);
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_free_next_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_heap_page *new_value = drb_ffi__ZTSP13mrb_heap_page_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS13mrb_heap_page *)DATA_PTR(self))->value)->free_next = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_free_prev_Get(mrb_state *state, mrb_value self) {
    mrb_heap_page record = drb_ffi__ZTS13mrb_heap_page_FromRuby(state, self);
    return drb_ffi__ZTSP13mrb_heap_page_ToRuby(state, record.free_prev);
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_free_prev_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct mrb_heap_page *new_value = drb_ffi__ZTSP13mrb_heap_page_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS13mrb_heap_page *)DATA_PTR(self))->value)->free_prev = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_old_Get(mrb_state *state, mrb_value self) {
    mrb_heap_page record = drb_ffi__ZTS13mrb_heap_page_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.old);
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_old_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    mrb_bool new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS13mrb_heap_page *)DATA_PTR(self))->value)->old = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_objects_Get(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot get incomplete array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS13mrb_heap_page_objects_Set(mrb_state *state, mrb_value self) {
    drb_api->mrb_raise(state, drb_api->drb_getruntime_error(state), "Cannot set incomplete array field");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSN3$_03$_1E_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTSN3$_03$_1E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSN3$_03$_1E *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "PIGPIO");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSN3$_03$_1E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSN3$_03$_1E_env_Get(mrb_state *state, mrb_value self) {
    union (anonymous union at ../include/mruby.h:158:3) record = drb_ffi__ZTSN3$_03$_1E_FromRuby(state, self);
    return drb_ffi__ZTSP4REnv_ToRuby(state, record.env);
}
static mrb_value drb_ffi__ZTSN3$_03$_1E_env_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct REnv *new_value = drb_ffi__ZTSP4REnv_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTSN3$_03$_1E *)DATA_PTR(self))->value)->env = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSN3$_03$_1E_target_class_Get(mrb_state *state, mrb_value self) {
    union (anonymous union at ../include/mruby.h:158:3) record = drb_ffi__ZTSN3$_03$_1E_FromRuby(state, self);
    return drb_ffi__ZTSP6RClass_ToRuby(state, record.target_class);
}
static mrb_value drb_ffi__ZTSN3$_03$_1E_target_class_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct RClass *new_value = drb_ffi__ZTSP6RClass_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTSN3$_03$_1E *)DATA_PTR(self))->value)->target_class = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi_fclose_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fclose': wrong number of arguments (%d for 1)", argc);
    int *__stream_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int ret_val = fclose(__stream_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fflush_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fflush': wrong number of arguments (%d for 1)", argc);
    int *__stream_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int ret_val = fflush(__stream_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_vfprintf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'vfprintf': wrong number of arguments (%d for 3)", argc);
    int *__s_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    char *__format_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int __arg_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = vfprintf(__s_0, __format_1, __arg_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_vprintf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'vprintf': wrong number of arguments (%d for 2)", argc);
    char *__format_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int __arg_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = vprintf(__format_0, __arg_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fgetc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fgetc': wrong number of arguments (%d for 1)", argc);
    int *__stream_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int ret_val = fgetc(__stream_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'getc': wrong number of arguments (%d for 1)", argc);
    int *__stream_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int ret_val = getc(__stream_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_getchar_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'getchar': wrong number of arguments (%d for 0)", argc);
    int ret_val = getchar();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fputc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fputc': wrong number of arguments (%d for 2)", argc);
    int __c_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *__stream_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = fputc(__c_0, __stream_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_putc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'putc': wrong number of arguments (%d for 2)", argc);
    int __c_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *__stream_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = putc(__c_0, __stream_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_putchar_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'putchar': wrong number of arguments (%d for 1)", argc);
    int __c_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = putchar(__c_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fputs_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fputs': wrong number of arguments (%d for 2)", argc);
    char *__s_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int *__stream_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = fputs(__s_0, __stream_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_puts_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'puts': wrong number of arguments (%d for 1)", argc);
    char *__s_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = puts(__s_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_ungetc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'ungetc': wrong number of arguments (%d for 2)", argc);
    int __c_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *__stream_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = ungetc(__c_0, __stream_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fwrite_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fwrite': wrong number of arguments (%d for 4)", argc);
    void *__ptr_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    int __size_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int __n_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int *__s_3 = drb_ffi__ZTSPi_FromRuby(state, args[3]);
    int ret_val = fwrite(__ptr_0, __size_1, __n_2, __s_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fseek_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fseek': wrong number of arguments (%d for 3)", argc);
    int *__stream_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    long __off_1 = drb_ffi__ZTSl_FromRuby(state, args[1]);
    int __whence_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = fseek(__stream_0, __off_1, __whence_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_rewind_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'rewind': wrong number of arguments (%d for 1)", argc);
    int *__stream_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    rewind(__stream_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_fgetpos_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fgetpos': wrong number of arguments (%d for 2)", argc);
    int *__stream_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int *__pos_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = fgetpos(__stream_0, __pos_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_fsetpos_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'fsetpos': wrong number of arguments (%d for 2)", argc);
    int *__stream_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int *__pos_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int ret_val = fsetpos(__stream_0, __pos_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_perror_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'perror': wrong number of arguments (%d for 1)", argc);
    char *__s_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    perror(__s_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi___uflow_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'__uflow': wrong number of arguments (%d for 1)", argc);
    int *_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int ret_val = __uflow(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi___overflow_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'__overflow': wrong number of arguments (%d for 2)", argc);
    int *_0 = drb_ffi__ZTSPi_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = __overflow(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_float_read_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_float_read': wrong number of arguments (%d for 2)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    double ret_val = mrb_float_read(_0, _1);
    return drb_ffi__ZTSd_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_val_union_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_val_union': wrong number of arguments (%d for 1)", argc);
    mrb_value v_0 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[0]);
    union mrb_value_ ret_val = mrb_val_union(v_0);
    return drb_ffi__ZTS10mrb_value__ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_word_boxing_cptr_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_word_boxing_cptr_value': wrong number of arguments (%d for 2)", argc);
    struct mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_word_boxing_cptr_value(_0, _1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_word_boxing_float_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_word_boxing_float_value': wrong number of arguments (%d for 2)", argc);
    struct mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_float _1 = drb_ffi__ZTSd_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_word_boxing_float_value(_0, _1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_word_boxing_int_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_word_boxing_int_value': wrong number of arguments (%d for 2)", argc);
    struct mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int mrb_int_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_word_boxing_int_value(_0, mrb_int_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_integer_func_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_integer_func': wrong number of arguments (%d for 1)", argc);
    mrb_value o_0 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[0]);
    int ret_val = mrb_integer_func(o_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_type_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_type': wrong number of arguments (%d for 1)", argc);
    mrb_value o_0 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[0]);
    enum mrb_vtype ret_val = mrb_type(o_0);
    return drb_ffi__ZTS9mrb_vtype_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_float_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_float_value': wrong number of arguments (%d for 2)", argc);
    struct mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_float f_1 = drb_ffi__ZTSd_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_float_value(mrb_0, f_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_cptr_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_cptr_value': wrong number of arguments (%d for 2)", argc);
    struct mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void *p_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_cptr_value(mrb_0, p_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_int_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_int_value': wrong number of arguments (%d for 2)", argc);
    struct mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int i_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_int_value(mrb_0, i_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_fixnum_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_fixnum_value': wrong number of arguments (%d for 1)", argc);
    int i_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    mrb_value ret_val = mrb_fixnum_value(i_0);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_symbol_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_symbol_value': wrong number of arguments (%d for 1)", argc);
    int i_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    mrb_value ret_val = mrb_symbol_value(i_0);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_value': wrong number of arguments (%d for 1)", argc);
    void *p_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    mrb_value ret_val = mrb_obj_value(p_0);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_nil_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_nil_value': wrong number of arguments (%d for 0)", argc);
    mrb_value ret_val = mrb_nil_value();
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_false_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_false_value': wrong number of arguments (%d for 0)", argc);
    mrb_value ret_val = mrb_false_value();
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_true_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_true_value': wrong number of arguments (%d for 0)", argc);
    mrb_value ret_val = mrb_true_value();
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_bool_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_bool_value': wrong number of arguments (%d for 1)", argc);
    mrb_bool boolean_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    mrb_value ret_val = mrb_bool_value(boolean_0);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_undef_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_undef_value': wrong number of arguments (%d for 0)", argc);
    mrb_value ret_val = mrb_undef_value();
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_objspace_each_objects_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_objspace_each_objects': wrong number of arguments (%d for 3)", argc);
    struct mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_each_object_callback *callback_1 = drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_FromRuby(state, args[1]);
    void *data_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    mrb_objspace_each_objects(mrb_0, callback_1, data_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_objspace_page_slot_size_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_objspace_page_slot_size': wrong number of arguments (%d for 0)", argc);
    int ret_val = mrb_objspace_page_slot_size();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_free_context_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_free_context': wrong number of arguments (%d for 2)", argc);
    struct mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct mrb_context *c_1 = drb_ffi__ZTSP11mrb_context_FromRuby(state, args[1]);
    mrb_free_context(mrb_0, c_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_object_dead_p_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_object_dead_p': wrong number of arguments (%d for 2)", argc);
    struct mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RBasic *object_1 = drb_ffi__ZTSP6RBasic_FromRuby(state, args[1]);
    mrb_bool ret_val = mrb_object_dead_p(mrb_0, object_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_class_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_class': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *name_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    struct RClass *super_2 = drb_ffi__ZTSP6RClass_FromRuby(state, args[2]);
    struct RClass *ret_val = mrb_define_class(mrb_0, name_1, super_2);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_class_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_class_id': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int name_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    struct RClass *super_2 = drb_ffi__ZTSP6RClass_FromRuby(state, args[2]);
    struct RClass *ret_val = mrb_define_class_id(mrb_0, name_1, super_2);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_module_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_module': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *name_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_define_module(mrb_0, name_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_module_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_module_id': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int name_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_define_module_id(mrb_0, name_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_singleton_class_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_singleton_class': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_singleton_class(mrb_0, val_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_singleton_class_ptr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_singleton_class_ptr': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_singleton_class_ptr(mrb_0, val_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_include_module_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_include_module': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    struct RClass *included_2 = drb_ffi__ZTSP6RClass_FromRuby(state, args[2]);
    mrb_include_module(mrb_0, cla_1, included_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_prepend_module_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_prepend_module': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    struct RClass *prepended_2 = drb_ffi__ZTSP6RClass_FromRuby(state, args[2]);
    mrb_prepend_module(mrb_0, cla_1, prepended_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_method_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_method': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_value (*func_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_aspec aspec_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    mrb_define_method(mrb_0, cla_1, name_2, func_3, aspec_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_method_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_method_id': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *c_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int mid_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value (*func_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_aspec aspec_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    mrb_define_method_id(mrb_0, c_1, mid_2, func_3, aspec_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_class_method_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_class_method': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_value (*fun_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_aspec aspec_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    mrb_define_class_method(mrb_0, cla_1, name_2, fun_3, aspec_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_class_method_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_class_method_id': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value (*fun_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_aspec aspec_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    mrb_define_class_method_id(mrb_0, cla_1, name_2, fun_3, aspec_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_singleton_method_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_singleton_method': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RObject *cla_1 = drb_ffi__ZTSP7RObject_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_value (*fun_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_aspec aspec_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    mrb_define_singleton_method(mrb_0, cla_1, name_2, fun_3, aspec_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_singleton_method_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_singleton_method_id': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RObject *cla_1 = drb_ffi__ZTSP7RObject_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value (*fun_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_aspec aspec_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    mrb_define_singleton_method_id(mrb_0, cla_1, name_2, fun_3, aspec_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_module_function_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_module_function': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_value (*fun_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_aspec aspec_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    mrb_define_module_function(mrb_0, cla_1, name_2, fun_3, aspec_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_module_function_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_module_function_id': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value (*fun_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_aspec aspec_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    mrb_define_module_function_id(mrb_0, cla_1, name_2, fun_3, aspec_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_const_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_const': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_value val_3 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[3]);
    mrb_define_const(mrb_0, cla_1, name_2, val_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_const_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_const_id': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value val_3 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[3]);
    mrb_define_const_id(mrb_0, cla_1, name_2, val_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_undef_method_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_undef_method': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cla_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_undef_method(mrb_0, cla_1, name_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_undef_method_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_undef_method_id': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int mrb_sym_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_undef_method_id(_0, _1, mrb_sym_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_undef_class_method_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_undef_class_method': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cls_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_undef_class_method(mrb_0, cls_1, name_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_undef_class_method_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_undef_class_method_id': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *cls_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_undef_class_method_id(mrb_0, cls_1, name_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_obj_new_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_new': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *c_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int argc_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value *argv_3 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_obj_new(mrb_0, c_1, argc_2, argv_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_new_instance_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_new_instance': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int argc_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    mrb_value *argv_2 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[2]);
    struct RClass *c_3 = drb_ffi__ZTSP6RClass_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_class_new_instance(mrb_0, argc_1, argv_2, c_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_new_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_new': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *super_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_class_new(mrb_0, super_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_module_new_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_module_new': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *ret_val = mrb_module_new(mrb_0);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_defined_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_defined': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *name_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    mrb_bool ret_val = mrb_class_defined(mrb_0, name_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_defined_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_defined_id': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int name_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    mrb_bool ret_val = mrb_class_defined_id(mrb_0, name_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_get_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_get': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *name_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_class_get(mrb_0, name_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_get_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_get_id': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int name_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_class_get_id(mrb_0, name_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_exc_get_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_exc_get_id': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int name_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_exc_get_id(mrb_0, name_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_defined_under_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_defined_under': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_class_defined_under(mrb_0, outer_1, name_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_defined_under_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_defined_under_id': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_class_defined_under_id(mrb_0, outer_1, name_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_get_under_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_get_under': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    struct RClass *ret_val = mrb_class_get_under(mrb_0, outer_1, name_2);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_get_under_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_get_under_id': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    struct RClass *ret_val = mrb_class_get_under_id(mrb_0, outer_1, name_2);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_module_get_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_module_get': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *name_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_module_get(mrb_0, name_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_module_get_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_module_get_id': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int name_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_module_get_id(mrb_0, name_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_module_get_under_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_module_get_under': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    struct RClass *ret_val = mrb_module_get_under(mrb_0, outer_1, name_2);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_module_get_under_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_module_get_under_id': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    struct RClass *ret_val = mrb_module_get_under_id(mrb_0, outer_1, name_2);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_notimplement_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_notimplement': wrong number of arguments (%d for 1)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_notimplement(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_notimplement_m_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_notimplement_m': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value _1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_notimplement_m(_0, _1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_dup_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_dup': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_obj_dup(mrb_0, obj_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_respond_to_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_respond_to': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *c_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int mid_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_obj_respond_to(mrb_0, c_1, mid_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_class_under_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_class_under': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    struct RClass *super_3 = drb_ffi__ZTSP6RClass_FromRuby(state, args[3]);
    struct RClass *ret_val = mrb_define_class_under(mrb_0, outer_1, name_2, super_3);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_class_under_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_class_under_id': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    struct RClass *super_3 = drb_ffi__ZTSP6RClass_FromRuby(state, args[3]);
    struct RClass *ret_val = mrb_define_class_under_id(mrb_0, outer_1, name_2, super_3);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_module_under_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_module_under': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *name_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    struct RClass *ret_val = mrb_define_module_under(mrb_0, outer_1, name_2);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_module_under_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_module_under_id': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *outer_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    struct RClass *ret_val = mrb_define_module_under_id(mrb_0, outer_1, name_2);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_get_mid_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_get_mid': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int ret_val = mrb_get_mid(mrb_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_get_argc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_get_argc': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int ret_val = mrb_get_argc(mrb_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_get_argv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_get_argv': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value *ret_val = mrb_get_argv(mrb_0);
    return drb_ffi__ZTSP9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_get_arg1_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_get_arg1': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value ret_val = mrb_get_arg1(mrb_0);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_funcall_argv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_funcall_argv': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int argc_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_value *argv_4 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[4]);
    mrb_value ret_val = mrb_funcall_argv(mrb_0, val_1, name_2, argc_3, argv_4);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_funcall_with_block_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_funcall_with_block': wrong number of arguments (%d for 6)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int name_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int argc_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_value *argv_4 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[4]);
    mrb_value block_5 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[5]);
    mrb_value ret_val = mrb_funcall_with_block(mrb_0, val_1, name_2, argc_3, argv_4, block_5);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_intern_cstr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_intern_cstr': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *str_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = mrb_intern_cstr(mrb_0, str_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_intern_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_intern': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int size_t_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = mrb_intern(_0, _1, size_t_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_intern_static_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_intern_static': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int size_t_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = mrb_intern_static(_0, _1, size_t_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_intern_str_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_intern_str': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value _1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int ret_val = mrb_intern_str(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_intern_check_cstr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_intern_check_cstr': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = mrb_intern_check_cstr(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_intern_check_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_intern_check': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int size_t_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = mrb_intern_check(_0, _1, size_t_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_intern_check_str_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_intern_check_str': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value _1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int ret_val = mrb_intern_check_str(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_check_intern_cstr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_check_intern_cstr': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_check_intern_cstr(_0, _1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_check_intern_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_check_intern': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int size_t_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_check_intern(_0, _1, size_t_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_check_intern_str_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_check_intern_str': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value _1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_check_intern_str(_0, _1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_sym_name_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_sym_name': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int mrb_sym_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = mrb_sym_name(_0, mrb_sym_1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_sym_name_len_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_sym_name_len': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int mrb_sym_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int *_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    char *ret_val = mrb_sym_name_len(_0, mrb_sym_1, _2);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_sym_dump_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_sym_dump': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int mrb_sym_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = mrb_sym_dump(_0, mrb_sym_1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_sym_str_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_sym_str': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int mrb_sym_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_sym_str(_0, mrb_sym_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_malloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_malloc': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int size_t_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = mrb_malloc(_0, size_t_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_calloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_calloc': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int size_t_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void *ret_val = mrb_calloc(_0, size_t_1, _2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_realloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_realloc': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int size_t_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void *ret_val = mrb_realloc(_0, _1, size_t_2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_realloc_simple_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_realloc_simple': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int size_t_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void *ret_val = mrb_realloc_simple(_0, _1, size_t_2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_malloc_simple_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_malloc_simple': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int size_t_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = mrb_malloc_simple(_0, size_t_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_alloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_alloc': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    enum mrb_vtype _1 = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[1]);
    struct RClass *_2 = drb_ffi__ZTSP6RClass_FromRuby(state, args[2]);
    struct RBasic *ret_val = mrb_obj_alloc(_0, _1, _2);
    return drb_ffi__ZTSP6RBasic_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_free_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_free': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    mrb_free(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_str_new_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_str_new': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *p_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int len_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_str_new(mrb_0, p_1, len_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_str_new_cstr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_str_new_cstr': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_str_new_cstr(_0, _1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_str_new_static_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_str_new_static': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *p_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int len_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_str_new_static(mrb_0, p_1, len_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_freeze_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_freeze': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value _1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_obj_freeze(_0, _1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_open_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_open': wrong number of arguments (%d for 0)", argc);
    mrb_state *ret_val = mrb_open();
    return drb_ffi__ZTSP9mrb_state_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_open_allocf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_open_allocf': wrong number of arguments (%d for 2)", argc);
    void *(*f_0)(struct mrb_state *, void *, int, void *) = drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_FromRuby(state, args[0]);
    void *ud_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    mrb_state *ret_val = mrb_open_allocf(f_0, ud_1);
    return drb_ffi__ZTSP9mrb_state_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_open_core_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_open_core': wrong number of arguments (%d for 2)", argc);
    void *(*f_0)(struct mrb_state *, void *, int, void *) = drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_FromRuby(state, args[0]);
    void *ud_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    mrb_state *ret_val = mrb_open_core(f_0, ud_1);
    return drb_ffi__ZTSP9mrb_state_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_close_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_close': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_close(mrb_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_default_allocf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_default_allocf': wrong number of arguments (%d for 4)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int size_t_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void *_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    void *ret_val = mrb_default_allocf(_0, _1, size_t_2, _3);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_top_self_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_top_self': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value ret_val = mrb_top_self(mrb_0);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_top_run_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_top_run': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RProc *proc_1 = drb_ffi__ZTSP5RProc_FromRuby(state, args[1]);
    mrb_value self_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    int stack_keep_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_top_run(mrb_0, proc_1, self_2, stack_keep_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_vm_run_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_vm_run': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RProc *proc_1 = drb_ffi__ZTSP5RProc_FromRuby(state, args[1]);
    mrb_value self_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    int stack_keep_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_vm_run(mrb_0, proc_1, self_2, stack_keep_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_vm_exec_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_vm_exec': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RProc *proc_1 = drb_ffi__ZTSP5RProc_FromRuby(state, args[1]);
    mrb_code *iseq_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_vm_exec(mrb_0, proc_1, iseq_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_p_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_p': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value _1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_p(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_obj_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_id': wrong number of arguments (%d for 1)", argc);
    mrb_value obj_0 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[0]);
    int ret_val = mrb_obj_id(obj_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_to_sym_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_to_sym': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value name_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int ret_val = mrb_obj_to_sym(mrb_0, name_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_eq_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_eq': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value a_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value b_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_obj_eq(mrb_0, a_1, b_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_equal_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_equal': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value a_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value b_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_obj_equal(mrb_0, a_1, b_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_equal_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_equal': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj1_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value obj2_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_equal(mrb_0, obj1_1, obj2_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_convert_to_integer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_convert_to_integer': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int base_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_convert_to_integer(mrb_0, val_1, base_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_Integer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_Integer': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_Integer(mrb_0, val_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_Float_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_Float': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_Float(mrb_0, val_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_inspect_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_inspect': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_inspect(mrb_0, obj_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_eql_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_eql': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj1_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value obj2_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_eql(mrb_0, obj1_1, obj2_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_cmp_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_cmp': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj1_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value obj2_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    int ret_val = mrb_cmp(mrb_0, obj1_1, obj2_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_gc_arena_save_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_gc_arena_save': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int ret_val = mrb_gc_arena_save(mrb_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_gc_arena_restore_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_gc_arena_restore': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int idx_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    mrb_gc_arena_restore(mrb_0, idx_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_garbage_collect_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_garbage_collect': wrong number of arguments (%d for 1)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_garbage_collect(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_full_gc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_full_gc': wrong number of arguments (%d for 1)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_full_gc(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_incremental_gc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_incremental_gc': wrong number of arguments (%d for 1)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_incremental_gc(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_gc_mark_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_gc_mark': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RBasic *_1 = drb_ffi__ZTSP6RBasic_FromRuby(state, args[1]);
    mrb_gc_mark(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_field_write_barrier_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_field_write_barrier': wrong number of arguments (%d for 3)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RBasic *_1 = drb_ffi__ZTSP6RBasic_FromRuby(state, args[1]);
    struct RBasic *_2 = drb_ffi__ZTSP6RBasic_FromRuby(state, args[2]);
    mrb_field_write_barrier(_0, _1, _2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_write_barrier_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_write_barrier': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RBasic *_1 = drb_ffi__ZTSP6RBasic_FromRuby(state, args[1]);
    mrb_write_barrier(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_type_convert_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_type_convert': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    enum mrb_vtype type_2 = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[2]);
    int method_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_type_convert(mrb_0, val_1, type_2, method_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_type_convert_check_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_type_convert_check': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    enum mrb_vtype type_2 = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[2]);
    int method_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_type_convert_check(mrb_0, val_1, type_2, method_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_any_to_s_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_any_to_s': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_any_to_s(mrb_0, obj_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_classname_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_classname': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    char *ret_val = mrb_obj_classname(mrb_0, obj_1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_class_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_class': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    struct RClass *ret_val = mrb_obj_class(mrb_0, obj_1);
    return drb_ffi__ZTSP6RClass_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_class_path_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_path': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *c_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_class_path(mrb_0, c_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_is_kind_of_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_is_kind_of': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    struct RClass *c_2 = drb_ffi__ZTSP6RClass_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_obj_is_kind_of(mrb_0, obj_1, c_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_inspect_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_inspect': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value self_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_obj_inspect(mrb_0, self_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_clone_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_clone': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value self_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_obj_clone(mrb_0, self_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_exc_new_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_exc_new': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *c_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *ptr_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    int len_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_exc_new(mrb_0, c_1, ptr_2, len_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_exc_raise_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_exc_raise': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value exc_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_exc_raise(mrb_0, exc_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_raise_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_raise': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *c_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *msg_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    mrb_raise(mrb_0, c_1, msg_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_frozen_error_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_frozen_error': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void *frozen_obj_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    mrb_frozen_error(mrb_0, frozen_obj_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_argnum_error_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_argnum_error': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int argc_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int min_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int max_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_argnum_error(mrb_0, argc_1, min_2, max_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_print_backtrace_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_print_backtrace': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_print_backtrace(mrb_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_print_error_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_print_error': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_print_error(mrb_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_vformat_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_vformat': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *format_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ap_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_vformat(mrb_0, format_1, ap_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_yield_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_yield': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value b_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value arg_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_yield(mrb_0, b_1, arg_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_yield_argv_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_yield_argv': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value b_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int argc_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value *argv_3 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_yield_argv(mrb_0, b_1, argc_2, argv_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_yield_with_class_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_yield_with_class': wrong number of arguments (%d for 6)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value b_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int argc_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value *argv_3 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[3]);
    mrb_value self_4 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[4]);
    struct RClass *c_5 = drb_ffi__ZTSP6RClass_FromRuby(state, args[5]);
    mrb_value ret_val = mrb_yield_with_class(mrb_0, b_1, argc_2, argv_3, self_4, c_5);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_yield_cont_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_yield_cont': wrong number of arguments (%d for 5)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value b_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value self_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    int argc_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_value *argv_4 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[4]);
    mrb_value ret_val = mrb_yield_cont(mrb_0, b_1, self_2, argc_3, argv_4);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_gc_protect_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_gc_protect': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_gc_protect(mrb_0, obj_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_gc_register_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_gc_register': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_gc_register(mrb_0, obj_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_gc_unregister_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_gc_unregister': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_gc_unregister(mrb_0, obj_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_to_int_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_to_int': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_to_int(mrb_0, val_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_to_str_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_to_str': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value val_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_to_str(mrb_0, val_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_check_type_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_check_type': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value x_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    enum mrb_vtype t_2 = drb_ffi__ZTS9mrb_vtype_FromRuby(state, args[2]);
    mrb_check_type(mrb_0, x_1, t_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_check_frozen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_check_frozen': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void *o_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    mrb_check_frozen(mrb_0, o_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_alias_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_alias': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *c_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *a_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    char *b_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    mrb_define_alias(mrb_0, c_1, a_2, b_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_define_alias_id_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_alias_id': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *c_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    int a_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int b_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    mrb_define_alias_id(mrb_0, c_1, a_2, b_3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_class_name_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_class_name': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct RClass *klass_1 = drb_ffi__ZTSP6RClass_FromRuby(state, args[1]);
    char *ret_val = mrb_class_name(mrb_0, klass_1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_define_global_const_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_define_global_const': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    char *name_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    mrb_value val_2 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[2]);
    mrb_define_global_const(mrb_0, name_1, val_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_attr_get_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_attr_get': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int id_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_attr_get(mrb_0, obj_1, id_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_respond_to_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_respond_to': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int mid_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_respond_to(mrb_0, obj_1, mid_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_obj_is_instance_of_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_obj_is_instance_of': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    struct RClass *c_2 = drb_ffi__ZTSP6RClass_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_obj_is_instance_of(mrb_0, obj_1, c_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_func_basic_p_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_func_basic_p': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value obj_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int mid_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value (*func_3)(struct mrb_state *, mrb_value) = drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_FromRuby(state, args[3]);
    mrb_bool ret_val = mrb_func_basic_p(mrb_0, obj_1, mid_2, func_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_fiber_resume_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_fiber_resume': wrong number of arguments (%d for 4)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value fib_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    int argc_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_value *argv_3 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[3]);
    mrb_value ret_val = mrb_fiber_resume(mrb_0, fib_1, argc_2, argv_3);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_fiber_yield_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_fiber_yield': wrong number of arguments (%d for 3)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int argc_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    mrb_value *argv_2 = drb_ffi__ZTSP9mrb_value_FromRuby(state, args[2]);
    mrb_value ret_val = mrb_fiber_yield(mrb_0, argc_1, argv_2);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_fiber_alive_p_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_fiber_alive_p': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_value fib_1 = drb_ffi__ZTS9mrb_value_FromRuby(state, args[1]);
    mrb_value ret_val = mrb_fiber_alive_p(mrb_0, fib_1);
    return drb_ffi__ZTS9mrb_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_stack_extend_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_stack_extend': wrong number of arguments (%d for 2)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int mrb_int_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    mrb_stack_extend(_0, mrb_int_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_pool_open_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_pool_open': wrong number of arguments (%d for 1)", argc);
    mrb_state *_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    struct mrb_pool *ret_val = mrb_pool_open(_0);
    return drb_ffi__ZTSP8mrb_pool_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_pool_close_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_pool_close': wrong number of arguments (%d for 1)", argc);
    struct mrb_pool *_0 = drb_ffi__ZTSP8mrb_pool_FromRuby(state, args[0]);
    mrb_pool_close(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_pool_alloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_pool_alloc': wrong number of arguments (%d for 2)", argc);
    struct mrb_pool *_0 = drb_ffi__ZTSP8mrb_pool_FromRuby(state, args[0]);
    int size_t_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = mrb_pool_alloc(_0, size_t_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_pool_realloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_pool_realloc': wrong number of arguments (%d for 4)", argc);
    struct mrb_pool *_0 = drb_ffi__ZTSP8mrb_pool_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int oldlen_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int newlen_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    void *ret_val = mrb_pool_realloc(_0, _1, oldlen_2, newlen_3);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_pool_can_realloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_pool_can_realloc': wrong number of arguments (%d for 3)", argc);
    struct mrb_pool *_0 = drb_ffi__ZTSP8mrb_pool_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int size_t_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    mrb_bool ret_val = mrb_pool_can_realloc(_0, _1, size_t_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_alloca_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_alloca': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    int size_t_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = mrb_alloca(mrb_0, size_t_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_mrb_state_atexit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_state_atexit': wrong number of arguments (%d for 2)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    void (*func_1)(struct mrb_state *) = drb_ffi__ZTSPFvP9mrb_stateE_FromRuby(state, args[1]);
    mrb_state_atexit(mrb_0, func_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_show_version_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_show_version': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_show_version(mrb_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_mrb_show_copyright_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'mrb_show_copyright': wrong number of arguments (%d for 1)", argc);
    mrb_state *mrb_0 = drb_ffi__ZTSP9mrb_state_FromRuby(state, args[0]);
    mrb_show_copyright(mrb_0);
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
    bridge_gpio_terminate();
    return mrb_nil_value();
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
    drb_api->mrb_define_module_function(state, module, "fclose", drb_ffi_fclose_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "fflush", drb_ffi_fflush_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "vfprintf", drb_ffi_vfprintf_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "vprintf", drb_ffi_vprintf_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "fgetc", drb_ffi_fgetc_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "getc", drb_ffi_getc_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "getchar", drb_ffi_getchar_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "fputc", drb_ffi_fputc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "putc", drb_ffi_putc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "putchar", drb_ffi_putchar_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "fputs", drb_ffi_fputs_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "puts", drb_ffi_puts_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "ungetc", drb_ffi_ungetc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "fwrite", drb_ffi_fwrite_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "fseek", drb_ffi_fseek_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "rewind", drb_ffi_rewind_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "fgetpos", drb_ffi_fgetpos_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "fsetpos", drb_ffi_fsetpos_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "perror", drb_ffi_perror_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "__uflow", drb_ffi___uflow_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "__overflow", drb_ffi___overflow_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_float_read", drb_ffi_mrb_float_read_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_val_union", drb_ffi_mrb_val_union_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_word_boxing_cptr_value", drb_ffi_mrb_word_boxing_cptr_value_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_word_boxing_float_value", drb_ffi_mrb_word_boxing_float_value_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_word_boxing_int_value", drb_ffi_mrb_word_boxing_int_value_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_integer_func", drb_ffi_mrb_integer_func_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_type", drb_ffi_mrb_type_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_float_value", drb_ffi_mrb_float_value_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_cptr_value", drb_ffi_mrb_cptr_value_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_int_value", drb_ffi_mrb_int_value_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_fixnum_value", drb_ffi_mrb_fixnum_value_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_symbol_value", drb_ffi_mrb_symbol_value_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_value", drb_ffi_mrb_obj_value_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_nil_value", drb_ffi_mrb_nil_value_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "mrb_false_value", drb_ffi_mrb_false_value_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "mrb_true_value", drb_ffi_mrb_true_value_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "mrb_bool_value", drb_ffi_mrb_bool_value_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_undef_value", drb_ffi_mrb_undef_value_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "mrb_objspace_each_objects", drb_ffi_mrb_objspace_each_objects_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_objspace_page_slot_size", drb_ffi_mrb_objspace_page_slot_size_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "mrb_free_context", drb_ffi_mrb_free_context_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_object_dead_p", drb_ffi_mrb_object_dead_p_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_define_class", drb_ffi_mrb_define_class_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_define_class_id", drb_ffi_mrb_define_class_id_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_define_module", drb_ffi_mrb_define_module_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_define_module_id", drb_ffi_mrb_define_module_id_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_singleton_class", drb_ffi_mrb_singleton_class_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_singleton_class_ptr", drb_ffi_mrb_singleton_class_ptr_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_include_module", drb_ffi_mrb_include_module_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_prepend_module", drb_ffi_mrb_prepend_module_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_define_method", drb_ffi_mrb_define_method_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_define_method_id", drb_ffi_mrb_define_method_id_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_define_class_method", drb_ffi_mrb_define_class_method_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_define_class_method_id", drb_ffi_mrb_define_class_method_id_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_define_singleton_method", drb_ffi_mrb_define_singleton_method_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_define_singleton_method_id", drb_ffi_mrb_define_singleton_method_id_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_define_module_function", drb_ffi_mrb_define_module_function_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_define_module_function_id", drb_ffi_mrb_define_module_function_id_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_define_const", drb_ffi_mrb_define_const_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_define_const_id", drb_ffi_mrb_define_const_id_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_undef_method", drb_ffi_mrb_undef_method_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_undef_method_id", drb_ffi_mrb_undef_method_id_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_undef_class_method", drb_ffi_mrb_undef_class_method_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_undef_class_method_id", drb_ffi_mrb_undef_class_method_id_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_new", drb_ffi_mrb_obj_new_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_class_new_instance", drb_ffi_mrb_class_new_instance_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_class_new", drb_ffi_mrb_class_new_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_module_new", drb_ffi_mrb_module_new_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_class_defined", drb_ffi_mrb_class_defined_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_class_defined_id", drb_ffi_mrb_class_defined_id_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_class_get", drb_ffi_mrb_class_get_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_class_get_id", drb_ffi_mrb_class_get_id_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_exc_get_id", drb_ffi_mrb_exc_get_id_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_class_defined_under", drb_ffi_mrb_class_defined_under_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_class_defined_under_id", drb_ffi_mrb_class_defined_under_id_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_class_get_under", drb_ffi_mrb_class_get_under_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_class_get_under_id", drb_ffi_mrb_class_get_under_id_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_module_get", drb_ffi_mrb_module_get_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_module_get_id", drb_ffi_mrb_module_get_id_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_module_get_under", drb_ffi_mrb_module_get_under_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_module_get_under_id", drb_ffi_mrb_module_get_under_id_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_notimplement", drb_ffi_mrb_notimplement_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_notimplement_m", drb_ffi_mrb_notimplement_m_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_dup", drb_ffi_mrb_obj_dup_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_respond_to", drb_ffi_mrb_obj_respond_to_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_define_class_under", drb_ffi_mrb_define_class_under_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_define_class_under_id", drb_ffi_mrb_define_class_under_id_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_define_module_under", drb_ffi_mrb_define_module_under_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_define_module_under_id", drb_ffi_mrb_define_module_under_id_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_get_mid", drb_ffi_mrb_get_mid_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_get_argc", drb_ffi_mrb_get_argc_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_get_argv", drb_ffi_mrb_get_argv_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_get_arg1", drb_ffi_mrb_get_arg1_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_funcall_argv", drb_ffi_mrb_funcall_argv_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_funcall_with_block", drb_ffi_mrb_funcall_with_block_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "mrb_intern_cstr", drb_ffi_mrb_intern_cstr_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_intern", drb_ffi_mrb_intern_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_intern_static", drb_ffi_mrb_intern_static_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_intern_str", drb_ffi_mrb_intern_str_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_intern_check_cstr", drb_ffi_mrb_intern_check_cstr_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_intern_check", drb_ffi_mrb_intern_check_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_intern_check_str", drb_ffi_mrb_intern_check_str_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_check_intern_cstr", drb_ffi_mrb_check_intern_cstr_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_check_intern", drb_ffi_mrb_check_intern_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_check_intern_str", drb_ffi_mrb_check_intern_str_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_sym_name", drb_ffi_mrb_sym_name_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_sym_name_len", drb_ffi_mrb_sym_name_len_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_sym_dump", drb_ffi_mrb_sym_dump_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_sym_str", drb_ffi_mrb_sym_str_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_malloc", drb_ffi_mrb_malloc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_calloc", drb_ffi_mrb_calloc_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_realloc", drb_ffi_mrb_realloc_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_realloc_simple", drb_ffi_mrb_realloc_simple_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_malloc_simple", drb_ffi_mrb_malloc_simple_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_alloc", drb_ffi_mrb_obj_alloc_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_free", drb_ffi_mrb_free_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_str_new", drb_ffi_mrb_str_new_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_str_new_cstr", drb_ffi_mrb_str_new_cstr_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_str_new_static", drb_ffi_mrb_str_new_static_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_freeze", drb_ffi_mrb_obj_freeze_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_open", drb_ffi_mrb_open_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "mrb_open_allocf", drb_ffi_mrb_open_allocf_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_open_core", drb_ffi_mrb_open_core_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_close", drb_ffi_mrb_close_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_default_allocf", drb_ffi_mrb_default_allocf_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_top_self", drb_ffi_mrb_top_self_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_top_run", drb_ffi_mrb_top_run_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_vm_run", drb_ffi_mrb_vm_run_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_vm_exec", drb_ffi_mrb_vm_exec_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_p", drb_ffi_mrb_p_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_id", drb_ffi_mrb_obj_id_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_to_sym", drb_ffi_mrb_obj_to_sym_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_eq", drb_ffi_mrb_obj_eq_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_equal", drb_ffi_mrb_obj_equal_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_equal", drb_ffi_mrb_equal_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_convert_to_integer", drb_ffi_mrb_convert_to_integer_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_Integer", drb_ffi_mrb_Integer_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_Float", drb_ffi_mrb_Float_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_inspect", drb_ffi_mrb_inspect_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_eql", drb_ffi_mrb_eql_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_cmp", drb_ffi_mrb_cmp_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_gc_arena_save", drb_ffi_mrb_gc_arena_save_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_gc_arena_restore", drb_ffi_mrb_gc_arena_restore_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_garbage_collect", drb_ffi_mrb_garbage_collect_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_full_gc", drb_ffi_mrb_full_gc_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_incremental_gc", drb_ffi_mrb_incremental_gc_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_gc_mark", drb_ffi_mrb_gc_mark_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_field_write_barrier", drb_ffi_mrb_field_write_barrier_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_write_barrier", drb_ffi_mrb_write_barrier_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_type_convert", drb_ffi_mrb_type_convert_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_type_convert_check", drb_ffi_mrb_type_convert_check_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_any_to_s", drb_ffi_mrb_any_to_s_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_classname", drb_ffi_mrb_obj_classname_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_class", drb_ffi_mrb_obj_class_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_class_path", drb_ffi_mrb_class_path_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_is_kind_of", drb_ffi_mrb_obj_is_kind_of_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_inspect", drb_ffi_mrb_obj_inspect_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_clone", drb_ffi_mrb_obj_clone_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_exc_new", drb_ffi_mrb_exc_new_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_exc_raise", drb_ffi_mrb_exc_raise_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_raise", drb_ffi_mrb_raise_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_frozen_error", drb_ffi_mrb_frozen_error_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_argnum_error", drb_ffi_mrb_argnum_error_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_print_backtrace", drb_ffi_mrb_print_backtrace_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_print_error", drb_ffi_mrb_print_error_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_vformat", drb_ffi_mrb_vformat_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_yield", drb_ffi_mrb_yield_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_yield_argv", drb_ffi_mrb_yield_argv_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_yield_with_class", drb_ffi_mrb_yield_with_class_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "mrb_yield_cont", drb_ffi_mrb_yield_cont_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "mrb_gc_protect", drb_ffi_mrb_gc_protect_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_gc_register", drb_ffi_mrb_gc_register_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_gc_unregister", drb_ffi_mrb_gc_unregister_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_to_int", drb_ffi_mrb_to_int_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_to_str", drb_ffi_mrb_to_str_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_check_type", drb_ffi_mrb_check_type_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_check_frozen", drb_ffi_mrb_check_frozen_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_define_alias", drb_ffi_mrb_define_alias_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_define_alias_id", drb_ffi_mrb_define_alias_id_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_class_name", drb_ffi_mrb_class_name_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_define_global_const", drb_ffi_mrb_define_global_const_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_attr_get", drb_ffi_mrb_attr_get_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_respond_to", drb_ffi_mrb_respond_to_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_obj_is_instance_of", drb_ffi_mrb_obj_is_instance_of_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_func_basic_p", drb_ffi_mrb_func_basic_p_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_fiber_resume", drb_ffi_mrb_fiber_resume_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_fiber_yield", drb_ffi_mrb_fiber_yield_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_fiber_alive_p", drb_ffi_mrb_fiber_alive_p_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_stack_extend", drb_ffi_mrb_stack_extend_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_pool_open", drb_ffi_mrb_pool_open_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_pool_close", drb_ffi_mrb_pool_close_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_pool_alloc", drb_ffi_mrb_pool_alloc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_pool_realloc", drb_ffi_mrb_pool_realloc_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "mrb_pool_can_realloc", drb_ffi_mrb_pool_can_realloc_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "mrb_alloca", drb_ffi_mrb_alloca_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_state_atexit", drb_ffi_mrb_state_atexit_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "mrb_show_version", drb_ffi_mrb_show_version_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "mrb_show_copyright", drb_ffi_mrb_show_copyright_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_initialise", drb_ffi_bridge_gpio_initialise_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_terminate", drb_ffi_bridge_gpio_terminate_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_set_mode", drb_ffi_bridge_gpio_set_mode_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_set_pull_up_down", drb_ffi_bridge_gpio_set_pull_up_down_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_glitch_filter", drb_ffi_bridge_gpio_glitch_filter_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_read", drb_ffi_bridge_gpio_read_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "bridge_gpio_write", drb_ffi_bridge_gpio_write_Binding, MRB_ARGS_REQ(2));
    struct RClass *IntPointerClass = drb_api->mrb_define_class_under(state, module, "IntPointer", object_class);
    drb_api->mrb_define_class_method(state, IntPointerClass, "new", drb_ffi__ZTSPi_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, IntPointerClass, "value", drb_ffi__ZTSPi_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, IntPointerClass, "[]", drb_ffi__ZTSPi_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, IntPointerClass, "[]=", drb_ffi__ZTSPi_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, IntPointerClass, "nil?", drb_ffi__ZTSPi_IsNil, MRB_ARGS_REQ(0));
    struct RClass *CharPointerClass = drb_api->mrb_define_class_under(state, module, "CharPointer", object_class);
    drb_api->mrb_define_class_method(state, CharPointerClass, "new", drb_ffi__ZTSPc_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "value", drb_ffi__ZTSPc_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "[]", drb_ffi__ZTSPc_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, CharPointerClass, "[]=", drb_ffi__ZTSPc_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, CharPointerClass, "nil?", drb_ffi__ZTSPc_IsNil, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "str", drb_ffi__ZTSPc_GetString, MRB_ARGS_REQ(0));
    struct RClass *VoidPointerClass = drb_api->mrb_define_class_under(state, module, "VoidPointer", object_class);
    struct RClass *CharPointerPointerClass = drb_api->mrb_define_class_under(state, module, "CharPointerPointer", object_class);
    drb_api->mrb_define_class_method(state, CharPointerPointerClass, "new", drb_ffi__ZTSPPc_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerPointerClass, "value", drb_ffi__ZTSPPc_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerPointerClass, "[]", drb_ffi__ZTSPPc_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, CharPointerPointerClass, "[]=", drb_ffi__ZTSPPc_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, CharPointerPointerClass, "nil?", drb_ffi__ZTSPPc_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Mrb_statePointerClass = drb_api->mrb_define_class_under(state, module, "Mrb_statePointer", object_class);
    drb_api->mrb_define_class_method(state, Mrb_statePointerClass, "new", drb_ffi__ZTSP9mrb_state_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_statePointerClass, "value", drb_ffi__ZTSP9mrb_state_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_statePointerClass, "[]", drb_ffi__ZTSP9mrb_state_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_statePointerClass, "[]=", drb_ffi__ZTSP9mrb_state_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Mrb_statePointerClass, "nil?", drb_ffi__ZTSP9mrb_state_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_0PointerClass = drb_api->mrb_define_class_under(state, module, "Function_0Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_0PointerClass, "new", drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_0PointerClass, "value", drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_0PointerClass, "[]", drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_0PointerClass, "[]=", drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_0PointerClass, "nil?", drb_ffi__ZTSPFiP9mrb_stateP6RBasicPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Mrb_contextPointerClass = drb_api->mrb_define_class_under(state, module, "Mrb_contextPointer", object_class);
    drb_api->mrb_define_class_method(state, Mrb_contextPointerClass, "new", drb_ffi__ZTSP11mrb_context_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextPointerClass, "value", drb_ffi__ZTSP11mrb_context_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextPointerClass, "[]", drb_ffi__ZTSP11mrb_context_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextPointerClass, "[]=", drb_ffi__ZTSP11mrb_context_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Mrb_contextPointerClass, "nil?", drb_ffi__ZTSP11mrb_context_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RBasicPointerClass = drb_api->mrb_define_class_under(state, module, "RBasicPointer", object_class);
    drb_api->mrb_define_class_method(state, RBasicPointerClass, "new", drb_ffi__ZTSP6RBasic_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicPointerClass, "value", drb_ffi__ZTSP6RBasic_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicPointerClass, "[]", drb_ffi__ZTSP6RBasic_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RBasicPointerClass, "[]=", drb_ffi__ZTSP6RBasic_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RBasicPointerClass, "nil?", drb_ffi__ZTSP6RBasic_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RClassPointerClass = drb_api->mrb_define_class_under(state, module, "RClassPointer", object_class);
    drb_api->mrb_define_class_method(state, RClassPointerClass, "new", drb_ffi__ZTSP6RClass_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RClassPointerClass, "value", drb_ffi__ZTSP6RClass_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RClassPointerClass, "[]", drb_ffi__ZTSP6RClass_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RClassPointerClass, "[]=", drb_ffi__ZTSP6RClass_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RClassPointerClass, "nil?", drb_ffi__ZTSP6RClass_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_1PointerClass = drb_api->mrb_define_class_under(state, module, "Function_1Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_1PointerClass, "new", drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_1PointerClass, "value", drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_1PointerClass, "[]", drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_1PointerClass, "[]=", drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_1PointerClass, "nil?", drb_ffi__ZTSPF9mrb_valueP9mrb_stateS_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RObjectPointerClass = drb_api->mrb_define_class_under(state, module, "RObjectPointer", object_class);
    drb_api->mrb_define_class_method(state, RObjectPointerClass, "new", drb_ffi__ZTSP7RObject_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectPointerClass, "value", drb_ffi__ZTSP7RObject_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectPointerClass, "[]", drb_ffi__ZTSP7RObject_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RObjectPointerClass, "[]=", drb_ffi__ZTSP7RObject_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RObjectPointerClass, "nil?", drb_ffi__ZTSP7RObject_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Mrb_valuePointerClass = drb_api->mrb_define_class_under(state, module, "Mrb_valuePointer", object_class);
    drb_api->mrb_define_class_method(state, Mrb_valuePointerClass, "new", drb_ffi__ZTSP9mrb_value_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_valuePointerClass, "value", drb_ffi__ZTSP9mrb_value_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_valuePointerClass, "[]", drb_ffi__ZTSP9mrb_value_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_valuePointerClass, "[]=", drb_ffi__ZTSP9mrb_value_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Mrb_valuePointerClass, "nil?", drb_ffi__ZTSP9mrb_value_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_2PointerClass = drb_api->mrb_define_class_under(state, module, "Function_2Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_2PointerClass, "new", drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_2PointerClass, "value", drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_2PointerClass, "[]", drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_2PointerClass, "[]=", drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_2PointerClass, "nil?", drb_ffi__ZTSPFPvP9mrb_stateS_iS_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RProcPointerClass = drb_api->mrb_define_class_under(state, module, "RProcPointer", object_class);
    drb_api->mrb_define_class_method(state, RProcPointerClass, "new", drb_ffi__ZTSP5RProc_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RProcPointerClass, "value", drb_ffi__ZTSP5RProc_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RProcPointerClass, "[]", drb_ffi__ZTSP5RProc_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RProcPointerClass, "[]=", drb_ffi__ZTSP5RProc_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RProcPointerClass, "nil?", drb_ffi__ZTSP5RProc_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Mrb_poolPointerClass = drb_api->mrb_define_class_under(state, module, "Mrb_poolPointer", object_class);
    drb_api->mrb_define_class_method(state, Mrb_poolPointerClass, "new", drb_ffi__ZTSP8mrb_pool_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_poolPointerClass, "value", drb_ffi__ZTSP8mrb_pool_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_poolPointerClass, "[]", drb_ffi__ZTSP8mrb_pool_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_poolPointerClass, "[]=", drb_ffi__ZTSP8mrb_pool_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Mrb_poolPointerClass, "nil?", drb_ffi__ZTSP8mrb_pool_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_3PointerClass = drb_api->mrb_define_class_under(state, module, "Function_3Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_3PointerClass, "new", drb_ffi__ZTSPFvP9mrb_stateE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_3PointerClass, "value", drb_ffi__ZTSPFvP9mrb_stateE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_3PointerClass, "[]", drb_ffi__ZTSPFvP9mrb_stateE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_3PointerClass, "[]=", drb_ffi__ZTSPFvP9mrb_stateE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_3PointerClass, "nil?", drb_ffi__ZTSPFvP9mrb_stateE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RFloatPointerClass = drb_api->mrb_define_class_under(state, module, "RFloatPointer", object_class);
    drb_api->mrb_define_class_method(state, RFloatPointerClass, "new", drb_ffi__ZTSP6RFloat_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatPointerClass, "value", drb_ffi__ZTSP6RFloat_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatPointerClass, "[]", drb_ffi__ZTSP6RFloat_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFloatPointerClass, "[]=", drb_ffi__ZTSP6RFloat_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RFloatPointerClass, "nil?", drb_ffi__ZTSP6RFloat_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RIntegerPointerClass = drb_api->mrb_define_class_under(state, module, "RIntegerPointer", object_class);
    drb_api->mrb_define_class_method(state, RIntegerPointerClass, "new", drb_ffi__ZTSP8RInteger_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerPointerClass, "value", drb_ffi__ZTSP8RInteger_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerPointerClass, "[]", drb_ffi__ZTSP8RInteger_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RIntegerPointerClass, "[]=", drb_ffi__ZTSP8RInteger_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RIntegerPointerClass, "nil?", drb_ffi__ZTSP8RInteger_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RCptrPointerClass = drb_api->mrb_define_class_under(state, module, "RCptrPointer", object_class);
    drb_api->mrb_define_class_method(state, RCptrPointerClass, "new", drb_ffi__ZTSP5RCptr_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrPointerClass, "value", drb_ffi__ZTSP5RCptr_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrPointerClass, "[]", drb_ffi__ZTSP5RCptr_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RCptrPointerClass, "[]=", drb_ffi__ZTSP5RCptr_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RCptrPointerClass, "nil?", drb_ffi__ZTSP5RCptr_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Mrb_jmpbufPointerClass = drb_api->mrb_define_class_under(state, module, "Mrb_jmpbufPointer", object_class);
    drb_api->mrb_define_class_method(state, Mrb_jmpbufPointerClass, "new", drb_ffi__ZTSP10mrb_jmpbuf_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_jmpbufPointerClass, "value", drb_ffi__ZTSP10mrb_jmpbuf_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_jmpbufPointerClass, "[]", drb_ffi__ZTSP10mrb_jmpbuf_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_jmpbufPointerClass, "[]=", drb_ffi__ZTSP10mrb_jmpbuf_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Mrb_jmpbufPointerClass, "nil?", drb_ffi__ZTSP10mrb_jmpbuf_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Iv_tblPointerClass = drb_api->mrb_define_class_under(state, module, "Iv_tblPointer", object_class);
    drb_api->mrb_define_class_method(state, Iv_tblPointerClass, "new", drb_ffi__ZTSP6iv_tbl_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Iv_tblPointerClass, "value", drb_ffi__ZTSP6iv_tbl_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Iv_tblPointerClass, "[]", drb_ffi__ZTSP6iv_tbl_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Iv_tblPointerClass, "[]=", drb_ffi__ZTSP6iv_tbl_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Iv_tblPointerClass, "nil?", drb_ffi__ZTSP6iv_tbl_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Symbol_namePointerClass = drb_api->mrb_define_class_under(state, module, "Symbol_namePointer", object_class);
    drb_api->mrb_define_class_method(state, Symbol_namePointerClass, "new", drb_ffi__ZTSP11symbol_name_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Symbol_namePointerClass, "value", drb_ffi__ZTSP11symbol_name_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Symbol_namePointerClass, "[]", drb_ffi__ZTSP11symbol_name_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Symbol_namePointerClass, "[]=", drb_ffi__ZTSP11symbol_name_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Symbol_namePointerClass, "nil?", drb_ffi__ZTSP11symbol_name_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_3PointerPointerClass = drb_api->mrb_define_class_under(state, module, "Function_3PointerPointer", object_class);
    drb_api->mrb_define_class_method(state, Function_3PointerPointerClass, "new", drb_ffi__ZTSPPFvP9mrb_stateE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_3PointerPointerClass, "value", drb_ffi__ZTSPPFvP9mrb_stateE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_3PointerPointerClass, "[]", drb_ffi__ZTSPPFvP9mrb_stateE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_3PointerPointerClass, "[]=", drb_ffi__ZTSPPFvP9mrb_stateE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_3PointerPointerClass, "nil?", drb_ffi__ZTSPPFvP9mrb_stateE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *PointerClass = drb_api->mrb_define_class_under(state, module, "Pointer", object_class);
    drb_api->mrb_define_class_method(state, PointerClass, "new", drb_ffi__ZTSP3$_0_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, PointerClass, "value", drb_ffi__ZTSP3$_0_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, PointerClass, "[]", drb_ffi__ZTSP3$_0_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, PointerClass, "[]=", drb_ffi__ZTSP3$_0_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, PointerClass, "nil?", drb_ffi__ZTSP3$_0_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RFiberPointerClass = drb_api->mrb_define_class_under(state, module, "RFiberPointer", object_class);
    drb_api->mrb_define_class_method(state, RFiberPointerClass, "new", drb_ffi__ZTSP6RFiber_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberPointerClass, "value", drb_ffi__ZTSP6RFiber_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberPointerClass, "[]", drb_ffi__ZTSP6RFiber_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFiberPointerClass, "[]=", drb_ffi__ZTSP6RFiber_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RFiberPointerClass, "nil?", drb_ffi__ZTSP6RFiber_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Mrb_heap_pagePointerClass = drb_api->mrb_define_class_under(state, module, "Mrb_heap_pagePointer", object_class);
    drb_api->mrb_define_class_method(state, Mrb_heap_pagePointerClass, "new", drb_ffi__ZTSP13mrb_heap_page_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pagePointerClass, "value", drb_ffi__ZTSP13mrb_heap_page_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pagePointerClass, "[]", drb_ffi__ZTSP13mrb_heap_page_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_heap_pagePointerClass, "[]=", drb_ffi__ZTSP13mrb_heap_page_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Mrb_heap_pagePointerClass, "nil?", drb_ffi__ZTSP13mrb_heap_page_IsNil, MRB_ARGS_REQ(0));
    struct RClass *RBasicPointerPointerClass = drb_api->mrb_define_class_under(state, module, "RBasicPointerPointer", object_class);
    drb_api->mrb_define_class_method(state, RBasicPointerPointerClass, "new", drb_ffi__ZTSPP6RBasic_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicPointerPointerClass, "value", drb_ffi__ZTSPP6RBasic_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicPointerPointerClass, "[]", drb_ffi__ZTSPP6RBasic_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RBasicPointerPointerClass, "[]=", drb_ffi__ZTSPP6RBasic_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, RBasicPointerPointerClass, "nil?", drb_ffi__ZTSPP6RBasic_IsNil, MRB_ARGS_REQ(0));
    struct RClass *REnvPointerClass = drb_api->mrb_define_class_under(state, module, "REnvPointer", object_class);
    drb_api->mrb_define_class_method(state, REnvPointerClass, "new", drb_ffi__ZTSP4REnv_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, REnvPointerClass, "value", drb_ffi__ZTSP4REnv_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, REnvPointerClass, "[]", drb_ffi__ZTSP4REnv_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, REnvPointerClass, "[]=", drb_ffi__ZTSP4REnv_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, REnvPointerClass, "nil?", drb_ffi__ZTSP4REnv_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Mrb_value_Class = drb_api->mrb_define_class_under(state, module, "Mrb_value_", object_class);
    drb_api->mrb_define_class_method(state, Mrb_value_Class, "new", drb_ffi__ZTS10mrb_value__New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_value_Class, "p", drb_ffi__ZTS10mrb_value__p_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_value_Class, "p=", drb_ffi__ZTS10mrb_value__p_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_value_Class, "bp", drb_ffi__ZTS10mrb_value__bp_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_value_Class, "bp=", drb_ffi__ZTS10mrb_value__bp_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_value_Class, "fp", drb_ffi__ZTS10mrb_value__fp_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_value_Class, "fp=", drb_ffi__ZTS10mrb_value__fp_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_value_Class, "ip", drb_ffi__ZTS10mrb_value__ip_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_value_Class, "ip=", drb_ffi__ZTS10mrb_value__ip_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_value_Class, "vp", drb_ffi__ZTS10mrb_value__vp_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_value_Class, "vp=", drb_ffi__ZTS10mrb_value__vp_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_value_Class, "w", drb_ffi__ZTS10mrb_value__w_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_value_Class, "w=", drb_ffi__ZTS10mrb_value__w_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_value_Class, "value", drb_ffi__ZTS10mrb_value__value_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_value_Class, "value=", drb_ffi__ZTS10mrb_value__value_Set, MRB_ARGS_REQ(1));
    struct RClass *Mrb_valueClass = drb_api->mrb_define_class_under(state, module, "Mrb_value", object_class);
    drb_api->mrb_define_class_method(state, Mrb_valueClass, "new", drb_ffi__ZTS9mrb_value_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_valueClass, "w", drb_ffi__ZTS9mrb_value_w_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_valueClass, "w=", drb_ffi__ZTS9mrb_value_w_Set, MRB_ARGS_REQ(1));
    struct RClass *Mrb_stateClass = drb_api->mrb_define_class_under(state, module, "Mrb_state", object_class);
    drb_api->mrb_define_class_method(state, Mrb_stateClass, "new", drb_ffi__ZTS9mrb_state_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "jmp", drb_ffi__ZTS9mrb_state_jmp_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "jmp=", drb_ffi__ZTS9mrb_state_jmp_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "allocf", drb_ffi__ZTS9mrb_state_allocf_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "allocf=", drb_ffi__ZTS9mrb_state_allocf_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "allocf_ud", drb_ffi__ZTS9mrb_state_allocf_ud_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "allocf_ud=", drb_ffi__ZTS9mrb_state_allocf_ud_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "c", drb_ffi__ZTS9mrb_state_c_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "c=", drb_ffi__ZTS9mrb_state_c_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "root_c", drb_ffi__ZTS9mrb_state_root_c_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "root_c=", drb_ffi__ZTS9mrb_state_root_c_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "globals", drb_ffi__ZTS9mrb_state_globals_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "globals=", drb_ffi__ZTS9mrb_state_globals_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "exc", drb_ffi__ZTS9mrb_state_exc_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "exc=", drb_ffi__ZTS9mrb_state_exc_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "top_self", drb_ffi__ZTS9mrb_state_top_self_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "top_self=", drb_ffi__ZTS9mrb_state_top_self_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "object_class", drb_ffi__ZTS9mrb_state_object_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "object_class=", drb_ffi__ZTS9mrb_state_object_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "class_class", drb_ffi__ZTS9mrb_state_class_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "class_class=", drb_ffi__ZTS9mrb_state_class_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "module_class", drb_ffi__ZTS9mrb_state_module_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "module_class=", drb_ffi__ZTS9mrb_state_module_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "proc_class", drb_ffi__ZTS9mrb_state_proc_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "proc_class=", drb_ffi__ZTS9mrb_state_proc_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "string_class", drb_ffi__ZTS9mrb_state_string_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "string_class=", drb_ffi__ZTS9mrb_state_string_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "array_class", drb_ffi__ZTS9mrb_state_array_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "array_class=", drb_ffi__ZTS9mrb_state_array_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "hash_class", drb_ffi__ZTS9mrb_state_hash_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "hash_class=", drb_ffi__ZTS9mrb_state_hash_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "range_class", drb_ffi__ZTS9mrb_state_range_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "range_class=", drb_ffi__ZTS9mrb_state_range_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "float_class", drb_ffi__ZTS9mrb_state_float_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "float_class=", drb_ffi__ZTS9mrb_state_float_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "integer_class", drb_ffi__ZTS9mrb_state_integer_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "integer_class=", drb_ffi__ZTS9mrb_state_integer_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "true_class", drb_ffi__ZTS9mrb_state_true_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "true_class=", drb_ffi__ZTS9mrb_state_true_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "false_class", drb_ffi__ZTS9mrb_state_false_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "false_class=", drb_ffi__ZTS9mrb_state_false_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "nil_class", drb_ffi__ZTS9mrb_state_nil_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "nil_class=", drb_ffi__ZTS9mrb_state_nil_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symbol_class", drb_ffi__ZTS9mrb_state_symbol_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symbol_class=", drb_ffi__ZTS9mrb_state_symbol_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "kernel_module", drb_ffi__ZTS9mrb_state_kernel_module_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "kernel_module=", drb_ffi__ZTS9mrb_state_kernel_module_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "gc", drb_ffi__ZTS9mrb_state_gc_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "gc=", drb_ffi__ZTS9mrb_state_gc_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "cache", drb_ffi__ZTS9mrb_state_cache_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "cache=", drb_ffi__ZTS9mrb_state_cache_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symidx", drb_ffi__ZTS9mrb_state_symidx_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symidx=", drb_ffi__ZTS9mrb_state_symidx_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symtbl", drb_ffi__ZTS9mrb_state_symtbl_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symtbl=", drb_ffi__ZTS9mrb_state_symtbl_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symhash", drb_ffi__ZTS9mrb_state_symhash_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symhash=", drb_ffi__ZTS9mrb_state_symhash_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symcapa", drb_ffi__ZTS9mrb_state_symcapa_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symcapa=", drb_ffi__ZTS9mrb_state_symcapa_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "sym_default", drb_ffi__ZTS9mrb_state_sym_default_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "sym_default=", drb_ffi__ZTS9mrb_state_sym_default_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "sym_initialize", drb_ffi__ZTS9mrb_state_sym_initialize_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "sym_initialize=", drb_ffi__ZTS9mrb_state_sym_initialize_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symbuf", drb_ffi__ZTS9mrb_state_symbuf_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "symbuf=", drb_ffi__ZTS9mrb_state_symbuf_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "eException_class", drb_ffi__ZTS9mrb_state_eException_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "eException_class=", drb_ffi__ZTS9mrb_state_eException_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "eStandardError_class", drb_ffi__ZTS9mrb_state_eStandardError_class_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "eStandardError_class=", drb_ffi__ZTS9mrb_state_eStandardError_class_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "nomem_err", drb_ffi__ZTS9mrb_state_nomem_err_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "nomem_err=", drb_ffi__ZTS9mrb_state_nomem_err_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "stack_err", drb_ffi__ZTS9mrb_state_stack_err_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "stack_err=", drb_ffi__ZTS9mrb_state_stack_err_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "ud", drb_ffi__ZTS9mrb_state_ud_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "ud=", drb_ffi__ZTS9mrb_state_ud_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "atexit_stack", drb_ffi__ZTS9mrb_state_atexit_stack_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "atexit_stack=", drb_ffi__ZTS9mrb_state_atexit_stack_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_stateClass, "atexit_stack_len", drb_ffi__ZTS9mrb_state_atexit_stack_len_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_stateClass, "atexit_stack_len=", drb_ffi__ZTS9mrb_state_atexit_stack_len_Set, MRB_ARGS_REQ(1));
    struct RClass *Mrb_contextClass = drb_api->mrb_define_class_under(state, module, "Mrb_context", object_class);
    drb_api->mrb_define_class_method(state, Mrb_contextClass, "new", drb_ffi__ZTS11mrb_context_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "prev", drb_ffi__ZTS11mrb_context_prev_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "prev=", drb_ffi__ZTS11mrb_context_prev_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextClass, "stbase", drb_ffi__ZTS11mrb_context_stbase_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "stbase=", drb_ffi__ZTS11mrb_context_stbase_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextClass, "stend", drb_ffi__ZTS11mrb_context_stend_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "stend=", drb_ffi__ZTS11mrb_context_stend_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextClass, "ci", drb_ffi__ZTS11mrb_context_ci_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "ci=", drb_ffi__ZTS11mrb_context_ci_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextClass, "cibase", drb_ffi__ZTS11mrb_context_cibase_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "cibase=", drb_ffi__ZTS11mrb_context_cibase_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextClass, "ciend", drb_ffi__ZTS11mrb_context_ciend_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "ciend=", drb_ffi__ZTS11mrb_context_ciend_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextClass, "status", drb_ffi__ZTS11mrb_context_status_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "status=", drb_ffi__ZTS11mrb_context_status_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextClass, "vmexec", drb_ffi__ZTS11mrb_context_vmexec_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "vmexec=", drb_ffi__ZTS11mrb_context_vmexec_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_contextClass, "fib", drb_ffi__ZTS11mrb_context_fib_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_contextClass, "fib=", drb_ffi__ZTS11mrb_context_fib_Set, MRB_ARGS_REQ(1));
    struct RClass *RBasicClass = drb_api->mrb_define_class_under(state, module, "RBasic", object_class);
    drb_api->mrb_define_class_method(state, RBasicClass, "new", drb_ffi__ZTS6RBasic_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicClass, "c", drb_ffi__ZTS6RBasic_c_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicClass, "c=", drb_ffi__ZTS6RBasic_c_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RBasicClass, "gcnext", drb_ffi__ZTS6RBasic_gcnext_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicClass, "gcnext=", drb_ffi__ZTS6RBasic_gcnext_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RBasicClass, "tt", drb_ffi__ZTS6RBasic_tt_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicClass, "tt=", drb_ffi__ZTS6RBasic_tt_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RBasicClass, "color", drb_ffi__ZTS6RBasic_color_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicClass, "color=", drb_ffi__ZTS6RBasic_color_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RBasicClass, "flags", drb_ffi__ZTS6RBasic_flags_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RBasicClass, "flags=", drb_ffi__ZTS6RBasic_flags_Set, MRB_ARGS_REQ(1));
    struct RClass *RObjectClass = drb_api->mrb_define_class_under(state, module, "RObject", object_class);
    drb_api->mrb_define_class_method(state, RObjectClass, "new", drb_ffi__ZTS7RObject_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectClass, "c", drb_ffi__ZTS7RObject_c_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectClass, "c=", drb_ffi__ZTS7RObject_c_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RObjectClass, "gcnext", drb_ffi__ZTS7RObject_gcnext_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectClass, "gcnext=", drb_ffi__ZTS7RObject_gcnext_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RObjectClass, "tt", drb_ffi__ZTS7RObject_tt_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectClass, "tt=", drb_ffi__ZTS7RObject_tt_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RObjectClass, "color", drb_ffi__ZTS7RObject_color_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectClass, "color=", drb_ffi__ZTS7RObject_color_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RObjectClass, "flags", drb_ffi__ZTS7RObject_flags_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectClass, "flags=", drb_ffi__ZTS7RObject_flags_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RObjectClass, "iv", drb_ffi__ZTS7RObject_iv_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RObjectClass, "iv=", drb_ffi__ZTS7RObject_iv_Set, MRB_ARGS_REQ(1));
    struct RClass *RFloatClass = drb_api->mrb_define_class_under(state, module, "RFloat", object_class);
    drb_api->mrb_define_class_method(state, RFloatClass, "new", drb_ffi__ZTS6RFloat_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatClass, "c", drb_ffi__ZTS6RFloat_c_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatClass, "c=", drb_ffi__ZTS6RFloat_c_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFloatClass, "gcnext", drb_ffi__ZTS6RFloat_gcnext_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatClass, "gcnext=", drb_ffi__ZTS6RFloat_gcnext_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFloatClass, "tt", drb_ffi__ZTS6RFloat_tt_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatClass, "tt=", drb_ffi__ZTS6RFloat_tt_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFloatClass, "color", drb_ffi__ZTS6RFloat_color_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatClass, "color=", drb_ffi__ZTS6RFloat_color_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFloatClass, "flags", drb_ffi__ZTS6RFloat_flags_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatClass, "flags=", drb_ffi__ZTS6RFloat_flags_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFloatClass, "f", drb_ffi__ZTS6RFloat_f_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFloatClass, "f=", drb_ffi__ZTS6RFloat_f_Set, MRB_ARGS_REQ(1));
    struct RClass *RIntegerClass = drb_api->mrb_define_class_under(state, module, "RInteger", object_class);
    drb_api->mrb_define_class_method(state, RIntegerClass, "new", drb_ffi__ZTS8RInteger_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerClass, "c", drb_ffi__ZTS8RInteger_c_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerClass, "c=", drb_ffi__ZTS8RInteger_c_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RIntegerClass, "gcnext", drb_ffi__ZTS8RInteger_gcnext_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerClass, "gcnext=", drb_ffi__ZTS8RInteger_gcnext_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RIntegerClass, "tt", drb_ffi__ZTS8RInteger_tt_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerClass, "tt=", drb_ffi__ZTS8RInteger_tt_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RIntegerClass, "color", drb_ffi__ZTS8RInteger_color_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerClass, "color=", drb_ffi__ZTS8RInteger_color_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RIntegerClass, "flags", drb_ffi__ZTS8RInteger_flags_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerClass, "flags=", drb_ffi__ZTS8RInteger_flags_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RIntegerClass, "i", drb_ffi__ZTS8RInteger_i_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RIntegerClass, "i=", drb_ffi__ZTS8RInteger_i_Set, MRB_ARGS_REQ(1));
    struct RClass *RCptrClass = drb_api->mrb_define_class_under(state, module, "RCptr", object_class);
    drb_api->mrb_define_class_method(state, RCptrClass, "new", drb_ffi__ZTS5RCptr_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrClass, "c", drb_ffi__ZTS5RCptr_c_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrClass, "c=", drb_ffi__ZTS5RCptr_c_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RCptrClass, "gcnext", drb_ffi__ZTS5RCptr_gcnext_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrClass, "gcnext=", drb_ffi__ZTS5RCptr_gcnext_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RCptrClass, "tt", drb_ffi__ZTS5RCptr_tt_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrClass, "tt=", drb_ffi__ZTS5RCptr_tt_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RCptrClass, "color", drb_ffi__ZTS5RCptr_color_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrClass, "color=", drb_ffi__ZTS5RCptr_color_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RCptrClass, "flags", drb_ffi__ZTS5RCptr_flags_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrClass, "flags=", drb_ffi__ZTS5RCptr_flags_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RCptrClass, "p", drb_ffi__ZTS5RCptr_p_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RCptrClass, "p=", drb_ffi__ZTS5RCptr_p_Set, MRB_ARGS_REQ(1));
    struct RClass *Mrb_gcClass = drb_api->mrb_define_class_under(state, module, "Mrb_gc", object_class);
    drb_api->mrb_define_class_method(state, Mrb_gcClass, "new", drb_ffi__ZTS6mrb_gc_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "heaps", drb_ffi__ZTS6mrb_gc_heaps_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "heaps=", drb_ffi__ZTS6mrb_gc_heaps_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "sweeps", drb_ffi__ZTS6mrb_gc_sweeps_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "sweeps=", drb_ffi__ZTS6mrb_gc_sweeps_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "free_heaps", drb_ffi__ZTS6mrb_gc_free_heaps_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "free_heaps=", drb_ffi__ZTS6mrb_gc_free_heaps_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "live", drb_ffi__ZTS6mrb_gc_live_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "live=", drb_ffi__ZTS6mrb_gc_live_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "arena", drb_ffi__ZTS6mrb_gc_arena_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "arena=", drb_ffi__ZTS6mrb_gc_arena_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "arena_capa", drb_ffi__ZTS6mrb_gc_arena_capa_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "arena_capa=", drb_ffi__ZTS6mrb_gc_arena_capa_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "arena_idx", drb_ffi__ZTS6mrb_gc_arena_idx_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "arena_idx=", drb_ffi__ZTS6mrb_gc_arena_idx_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "state", drb_ffi__ZTS6mrb_gc_state_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "state=", drb_ffi__ZTS6mrb_gc_state_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "current_white_part", drb_ffi__ZTS6mrb_gc_current_white_part_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "current_white_part=", drb_ffi__ZTS6mrb_gc_current_white_part_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "gray_list", drb_ffi__ZTS6mrb_gc_gray_list_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "gray_list=", drb_ffi__ZTS6mrb_gc_gray_list_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "atomic_gray_list", drb_ffi__ZTS6mrb_gc_atomic_gray_list_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "atomic_gray_list=", drb_ffi__ZTS6mrb_gc_atomic_gray_list_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "live_after_mark", drb_ffi__ZTS6mrb_gc_live_after_mark_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "live_after_mark=", drb_ffi__ZTS6mrb_gc_live_after_mark_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "threshold", drb_ffi__ZTS6mrb_gc_threshold_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "threshold=", drb_ffi__ZTS6mrb_gc_threshold_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "interval_ratio", drb_ffi__ZTS6mrb_gc_interval_ratio_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "interval_ratio=", drb_ffi__ZTS6mrb_gc_interval_ratio_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "step_ratio", drb_ffi__ZTS6mrb_gc_step_ratio_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "step_ratio=", drb_ffi__ZTS6mrb_gc_step_ratio_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "iterating", drb_ffi__ZTS6mrb_gc_iterating_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "iterating=", drb_ffi__ZTS6mrb_gc_iterating_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "disabled", drb_ffi__ZTS6mrb_gc_disabled_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "disabled=", drb_ffi__ZTS6mrb_gc_disabled_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "full", drb_ffi__ZTS6mrb_gc_full_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "full=", drb_ffi__ZTS6mrb_gc_full_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "generational", drb_ffi__ZTS6mrb_gc_generational_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "generational=", drb_ffi__ZTS6mrb_gc_generational_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "out_of_memory", drb_ffi__ZTS6mrb_gc_out_of_memory_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "out_of_memory=", drb_ffi__ZTS6mrb_gc_out_of_memory_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_gcClass, "majorgc_old_threshold", drb_ffi__ZTS6mrb_gc_majorgc_old_threshold_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_gcClass, "majorgc_old_threshold=", drb_ffi__ZTS6mrb_gc_majorgc_old_threshold_Set, MRB_ARGS_REQ(1));
    struct RClass *Class = drb_api->mrb_define_class_under(state, module, "", object_class);
    drb_api->mrb_define_class_method(state, Class, "new", drb_ffi__ZTS3$_0_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "mid", drb_ffi__ZTS3$_0_mid_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "mid=", drb_ffi__ZTS3$_0_mid_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "argc", drb_ffi__ZTS3$_0_argc_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "argc=", drb_ffi__ZTS3$_0_argc_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "acc", drb_ffi__ZTS3$_0_acc_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "acc=", drb_ffi__ZTS3$_0_acc_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "proc", drb_ffi__ZTS3$_0_proc_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "proc=", drb_ffi__ZTS3$_0_proc_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "stack", drb_ffi__ZTS3$_0_stack_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "stack=", drb_ffi__ZTS3$_0_stack_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "pc", drb_ffi__ZTS3$_0_pc_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "pc=", drb_ffi__ZTS3$_0_pc_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Class, "u", drb_ffi__ZTS3$_0_u_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Class, "u=", drb_ffi__ZTS3$_0_u_Set, MRB_ARGS_REQ(1));
    struct RClass *RFiberClass = drb_api->mrb_define_class_under(state, module, "RFiber", object_class);
    drb_api->mrb_define_class_method(state, RFiberClass, "new", drb_ffi__ZTS6RFiber_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberClass, "c", drb_ffi__ZTS6RFiber_c_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberClass, "c=", drb_ffi__ZTS6RFiber_c_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFiberClass, "gcnext", drb_ffi__ZTS6RFiber_gcnext_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberClass, "gcnext=", drb_ffi__ZTS6RFiber_gcnext_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFiberClass, "tt", drb_ffi__ZTS6RFiber_tt_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberClass, "tt=", drb_ffi__ZTS6RFiber_tt_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFiberClass, "color", drb_ffi__ZTS6RFiber_color_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberClass, "color=", drb_ffi__ZTS6RFiber_color_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFiberClass, "flags", drb_ffi__ZTS6RFiber_flags_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberClass, "flags=", drb_ffi__ZTS6RFiber_flags_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, RFiberClass, "cxt", drb_ffi__ZTS6RFiber_cxt_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, RFiberClass, "cxt=", drb_ffi__ZTS6RFiber_cxt_Set, MRB_ARGS_REQ(1));
    struct RClass *Mrb_heap_pageClass = drb_api->mrb_define_class_under(state, module, "Mrb_heap_page", object_class);
    drb_api->mrb_define_class_method(state, Mrb_heap_pageClass, "new", drb_ffi__ZTS13mrb_heap_page_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "freelist", drb_ffi__ZTS13mrb_heap_page_freelist_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "freelist=", drb_ffi__ZTS13mrb_heap_page_freelist_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "prev", drb_ffi__ZTS13mrb_heap_page_prev_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "prev=", drb_ffi__ZTS13mrb_heap_page_prev_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "next", drb_ffi__ZTS13mrb_heap_page_next_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "next=", drb_ffi__ZTS13mrb_heap_page_next_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "free_next", drb_ffi__ZTS13mrb_heap_page_free_next_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "free_next=", drb_ffi__ZTS13mrb_heap_page_free_next_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "free_prev", drb_ffi__ZTS13mrb_heap_page_free_prev_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "free_prev=", drb_ffi__ZTS13mrb_heap_page_free_prev_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "old", drb_ffi__ZTS13mrb_heap_page_old_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "old=", drb_ffi__ZTS13mrb_heap_page_old_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "objects", drb_ffi__ZTS13mrb_heap_page_objects_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Mrb_heap_pageClass, "objects=", drb_ffi__ZTS13mrb_heap_page_objects_Set, MRB_ARGS_REQ(1));
}
