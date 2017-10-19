#ifndef GG_120_NONTERMS
#define GG_120_NONTERMS

#define typedef_name 1000
#define namespace_name 1003
#define original_namespace_name 1006
#define class_name 1009
#define enum_name 1014
#define template_name 1017

#define identifier 1020
#define literal 1030
#define integer_literal 1050
#define character_literal 1060
#define floating_literal 1070
#define string_literal 1080
#define boolean_literal 1090

#define program_start 1100

#define declaration_seq_opt 1200
#define nested_name_specifier_opt 1250
#define expression_list_opt 1300
#define COLONCOLON_opt 1350
#define new_placement_opt 1400
#define new_initializer_opt 1450
#define new_declarator_opt 1500
#define expression_opt 1550
#define statement_seq_opt 1600
#define condition_opt 1650
#define enumerator_list_opt 1700
#define initializer_opt 1750
#define constant_expression_opt 1800
#define abstract_declarator_opt 1850
#define type_specifier_seq_opt 1900
#define direct_abstract_declarator_opt 1950
#define ctor_initializer_opt 2000
#define COMMA_opt 2050
#define parameter_declaration_clause_opt 2100
#define member_specification_opt 2150
#define SEMICOLON_opt 2200
#define conversion_declarator_opt 2250
#define EXPORT_opt 2300
#define handler_seq_opt 2350
#define assignment_expression_opt 2400
#define type_id_list_opt 2450

#define primary_expression 2500
#define id_expression 2550
#define unqualified_id 2600
#define qualified_id 2650
#define nested_name_specifier 2700
#define postfix_expression 2750
#define expression_list 2800
#define unary_expression 2850
#define unary_operator 2900
#define new_expression 2950
#define new_placement 3000
#define new_type_id 3050
#define new_declarator 3100
#define direct_new_declarator 3150
#define new_initializer 3200
#define delete_expression 3250
#define cast_expression 3300
#define pm_expression 3350
#define multiplicative_expression 3400
#define additive_expression 3450
#define shift_expression 3500
#define relational_expression 3550
#define equality_expression 3600
#define and_expression 3650
#define exclusive_or_expression 3700
#define inclusive_or_expression 3750
#define logical_and_expression 3800
#define logical_or_expression 3850
#define conditional_expression 3900
#define assignment_expression 3950
#define assignment_operator 4000
#define expression 4050
#define constant_expression 4100

#define statement 4150
#define labeled_statement 4200
#define expression_statement 4250
#define compound_statement 4300
#define statement_seq 4350
#define selection_statement 4400
#define condition 4450
#define iteration_statement 4500
#define for_init_statement 4550
#define jump_statement 4600
#define declaration_statement 4650

#define declaration_seq 4700
#define declaration 4750
#define block_declaration 4800
#define simple_declaration 4850
#define decl_specifier 4900
#define decl_specifier_seq 4950
#define storage_class_specifier 5000
#define function_specifier 5050
#define type_specifier 5150
#define simple_type_specifier 5150
#define type_name 5200
#define elaborated_type_specifier 5250

#define enum_specifier 5300
#define enumerator_list 5350
#define enumerator_definition 5400
#define enumerator 5450

#define namespace_definition 5500
#define named_namespace_definition 5550
#define original_namespace_definition 5600
#define extension_namespace_definition 5650
#define unnamed_namespace_definition 5700
#define namespace_body 5750

#define namespace_alias_definition 5800
#define qualified_namespace_specifier 5850
#define using_declaration 5900
#define using_directive 5950
#define asm_definition 6000
#define linkage_specification 6050

#define init_declarator_list 6100
#define init_declarator 6150
#define declarator 6200
#define direct_declarator 6250
#define ptr_operator 6300
#define cv_qualifier_seq 6350
#define cv_qualifier 6400
#define declarator_id 6450
#define type_id 6500
#define type_specifier_seq 6550
#define abstract_declarator 6600
#define direct_abstract_declarator 6650
#define parameter_declaration_clause 6700
#define parameter_declaration_list 6750
#define parameter_declaration 6800
#define function_definition 6850
#define function_body 6900
#define initializer 6950
#define initializer_clause 7000
#define initializer_list 7050

#define class_specifier 7100
#define class_head 7150
#define class_key 7200
#define member_specification 7250
#define member_declaration 7300
#define member_declarator_list 7350
#define member_declarator 7400

#define pure_specifier 7450
#define constant_initializer 7500

#define base_clause 7550
#define base_specifier_list 7600
#define base_specifier 7660
#define access_specifier 7700

#define conversion_function_id 7750
#define conversion_type_id 7800
#define conversion_declarator 7850
#define ctor_initializer 7900
#define mem_initializer_list 7950
#define mem_initializer 8000
#define mem_initializer_id 8050

#define operator_function_id 8100
#define operator 8150

#define template_declaration 8250
#define template_parameter_list 8300
#define template_parameter 8350
#define type_parameter 8400
#define template_id 8450
#define template_argument_list 8500
#define template_argument 8550
#define explicit_instantiation 8600
#define explicit_specialization 8650

#define try_block 8700
#define function_try_block 8750
#define handler_seq 8800
#define handler 8850
#define exception_declaration 8900
#define throw_expression 8950
#define exception_specification 9000
#define type_id_list 9050

#define lexical_error 10000
#define parse_error 10005
#define program_error 10010
#define file_error 10015
#define unknown_error 10020 

#endif