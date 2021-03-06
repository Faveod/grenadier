#include "tree_sitter.h"

VALUE mTreeSitter;

void Init_tree_sitter() {
  mTreeSitter = rb_define_module("TreeSitter");

  rb_define_const(mTreeSitter, "LANGUAGE_VERSION",
                  INT2NUM(TREE_SITTER_LANGUAGE_VERSION));
  rb_define_const(mTreeSitter, "MIN_COMPATIBLE_LANGUAGE_VERSION",
                  TREE_SITTER_MIN_COMPATIBLE_LANGUAGE_VERSION);

  init_encoding();
  init_input();
  init_input_edit();
  init_language();
  init_logger();
  init_node();
  init_parser();
  init_point();
  init_quantifier();
  init_query();
  init_query_capture();
  init_query_cursor();
  init_query_error();
  init_query_match();
  init_query_predicate_step();
  init_range();
  init_symbol_type();
  init_tree();
  init_tree_cursor();
}
