#ifndef _RB_TREE_SITTER_H
#define _RB_TREE_SITTER_H

#include <fcntl.h>
#include <ruby.h>
#include <stdio.h>
#include <tree_sitter/api.h>

// VALUE to TS* converters
TSInput *value_to_input(VALUE);
TSInputEncoding value_to_encoding(VALUE);
TSInputEdit *value_to_input_edit(VALUE);
TSLanguage *value_to_language(VALUE);
TSLogger *value_to_logger(VALUE);
TSNode *value_to_node(VALUE);
TSPoint *value_to_point(VALUE);
TSRange *value_to_range(VALUE);
TSTree *value_to_tree(VALUE);
TSTreeCursor *value_to_tree_cursor(VALUE);

// TS* to VALUE converters
VALUE new_input(const TSInput *);
VALUE new_language(const TSLanguage *);
VALUE new_logger(const TSLogger *);
VALUE new_node(const TSNode *);
VALUE new_range(const TSRange *, bool);
VALUE new_point(const TSPoint *);
VALUE new_tree(const TSTree *);

// All init_* functions are called from Init_tree_sitter
void init_encoding(void);
void init_input(void);
void init_logger(void);
void init_language(void);
void init_parser(void);
void init_range(void);
void init_tree(void);
void init_tree_cursor(void);

// This is a special entry-point for the extension
void Init_tree_sitter(void);

#endif
