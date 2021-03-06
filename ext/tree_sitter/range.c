#include "tree_sitter.h"

extern VALUE mTreeSitter;

VALUE cRange;

DATA_WRAP(Range, range)
DATA_DEFINE_ACCESSOR(range, start_point, new_point_by_val, value_to_point)
DATA_DEFINE_ACCESSOR(range, end_point, new_point_by_val, value_to_point)
DATA_DEFINE_ACCESSOR(range, start_byte, UINT2NUM, NUM2UINT)
DATA_DEFINE_ACCESSOR(range, end_byte, UINT2NUM, NUM2UINT)

static VALUE range_inspect(VALUE self) {
  range_t *range = unwrap(self);
  return rb_sprintf("{start_point= %+" PRIsVALUE ", end_point=%+" PRIsVALUE
                    ", start_byte=%i, end_byte=%i}",
                    new_point_by_val(range->data.start_point),
                    new_point_by_val(range->data.end_point),
                    range->data.start_byte, range->data.end_byte);
}

void init_range(void) {
  cRange = rb_define_class_under(mTreeSitter, "Range", rb_cObject);

  rb_define_alloc_func(cRange, range_allocate);

  /* Class methods */
  DECLARE_ACCESSOR(cRange, range, start_point)
  DECLARE_ACCESSOR(cRange, range, end_point)
  DECLARE_ACCESSOR(cRange, range, start_byte)
  DECLARE_ACCESSOR(cRange, range, end_byte)

  rb_define_method(cRange, "inspect", range_inspect, 0);
  rb_define_method(cRange, "to_s", range_inspect, 0);
}
