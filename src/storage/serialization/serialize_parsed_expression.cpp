//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/format_serializer.hpp"
#include "duckdb/common/serializer/format_deserializer.hpp"
#include "duckdb/parser/expression/list.hpp"

namespace duckdb {

void ParsedExpression::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty("class", expression_class);
	serializer.WriteProperty("type", type);
	serializer.WriteProperty("alias", alias);
}

unique_ptr<ParsedExpression> ParsedExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto expression_class = deserializer.ReadProperty<ExpressionClass>("class");
	auto type = deserializer.ReadProperty<ExpressionType>("type");
	auto alias = deserializer.ReadProperty<string>("alias");
	deserializer.Set<ExpressionType>(type);
	unique_ptr<ParsedExpression> result;
	switch (expression_class) {
	case ExpressionClass::BETWEEN:
		result = BetweenExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::CASE:
		result = CaseExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::CAST:
		result = CastExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::COLLATE:
		result = CollateExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::COLUMN_REF:
		result = ColumnRefExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::COMPARISON:
		result = ComparisonExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::CONJUNCTION:
		result = ConjunctionExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::CONSTANT:
		result = ConstantExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::DEFAULT:
		result = DefaultExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::FUNCTION:
		result = FunctionExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::LAMBDA:
		result = LambdaExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::OPERATOR:
		result = OperatorExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::PARAMETER:
		result = ParameterExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::POSITIONAL_REFERENCE:
		result = PositionalReferenceExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::STAR:
		result = StarExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::SUBQUERY:
		result = SubqueryExpression::FormatDeserialize(deserializer);
		break;
	case ExpressionClass::WINDOW:
		result = WindowExpression::FormatDeserialize(deserializer);
		break;
	default:
		throw SerializationException("Unsupported type for deserialization of ParsedExpression!");
	}
	deserializer.Unset<ExpressionType>();
	result->alias = std::move(alias);
	return result;
}

void BetweenExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("input", *input);
	serializer.WriteProperty("lower", *lower);
	serializer.WriteProperty("upper", *upper);
}

unique_ptr<ParsedExpression> BetweenExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<BetweenExpression>(new BetweenExpression());
	deserializer.ReadProperty("input", result->input);
	deserializer.ReadProperty("lower", result->lower);
	deserializer.ReadProperty("upper", result->upper);
	return std::move(result);
}

void CaseExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("case_checks", case_checks);
	serializer.WriteProperty("else_expr", *else_expr);
}

unique_ptr<ParsedExpression> CaseExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<CaseExpression>(new CaseExpression());
	deserializer.ReadProperty("case_checks", result->case_checks);
	deserializer.ReadProperty("else_expr", result->else_expr);
	return std::move(result);
}

void CastExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("child", *child);
	serializer.WriteProperty("cast_type", cast_type);
	serializer.WriteProperty("try_cast", try_cast);
}

unique_ptr<ParsedExpression> CastExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<CastExpression>(new CastExpression());
	deserializer.ReadProperty("child", result->child);
	deserializer.ReadProperty("cast_type", result->cast_type);
	deserializer.ReadProperty("try_cast", result->try_cast);
	return std::move(result);
}

void CollateExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("child", *child);
	serializer.WriteProperty("collation", collation);
}

unique_ptr<ParsedExpression> CollateExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<CollateExpression>(new CollateExpression());
	deserializer.ReadProperty("child", result->child);
	deserializer.ReadProperty("collation", result->collation);
	return std::move(result);
}

void ColumnRefExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("column_names", column_names);
}

unique_ptr<ParsedExpression> ColumnRefExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ColumnRefExpression>(new ColumnRefExpression());
	deserializer.ReadProperty("column_names", result->column_names);
	return std::move(result);
}

void ComparisonExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("left", *left);
	serializer.WriteProperty("right", *right);
}

unique_ptr<ParsedExpression> ComparisonExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ComparisonExpression>(new ComparisonExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty("left", result->left);
	deserializer.ReadProperty("right", result->right);
	return std::move(result);
}

void ConjunctionExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("children", children);
}

unique_ptr<ParsedExpression> ConjunctionExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ConjunctionExpression>(new ConjunctionExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty("children", result->children);
	return std::move(result);
}

void ConstantExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("value", value);
}

unique_ptr<ParsedExpression> ConstantExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ConstantExpression>(new ConstantExpression());
	deserializer.ReadProperty("value", result->value);
	return std::move(result);
}

void DefaultExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
}

unique_ptr<ParsedExpression> DefaultExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<DefaultExpression>(new DefaultExpression());
	return std::move(result);
}

void FunctionExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("function_name", function_name);
	serializer.WriteProperty("schema", schema);
	serializer.WriteProperty("children", children);
	serializer.WriteOptionalProperty("filter", filter);
	serializer.WriteProperty("order_bys", (ResultModifier &)*order_bys);
	serializer.WriteProperty("distinct", distinct);
	serializer.WriteProperty("is_operator", is_operator);
	serializer.WriteProperty("export_state", export_state);
	serializer.WriteProperty("catalog", catalog);
}

unique_ptr<ParsedExpression> FunctionExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<FunctionExpression>(new FunctionExpression());
	deserializer.ReadProperty("function_name", result->function_name);
	deserializer.ReadProperty("schema", result->schema);
	deserializer.ReadProperty("children", result->children);
	deserializer.ReadOptionalProperty("filter", result->filter);
	auto order_bys = deserializer.ReadProperty<unique_ptr<ResultModifier>>("order_bys");
	result->order_bys = unique_ptr_cast<ResultModifier, OrderModifier>(std::move(order_bys));
	deserializer.ReadProperty("distinct", result->distinct);
	deserializer.ReadProperty("is_operator", result->is_operator);
	deserializer.ReadProperty("export_state", result->export_state);
	deserializer.ReadProperty("catalog", result->catalog);
	return std::move(result);
}

void LambdaExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("lhs", *lhs);
	serializer.WriteProperty("expr", *expr);
}

unique_ptr<ParsedExpression> LambdaExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LambdaExpression>(new LambdaExpression());
	deserializer.ReadProperty("lhs", result->lhs);
	deserializer.ReadProperty("expr", result->expr);
	return std::move(result);
}

void OperatorExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("children", children);
}

unique_ptr<ParsedExpression> OperatorExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<OperatorExpression>(new OperatorExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty("children", result->children);
	return std::move(result);
}

void ParameterExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("identifier", identifier);
}

unique_ptr<ParsedExpression> ParameterExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<ParameterExpression>(new ParameterExpression());
	deserializer.ReadProperty("identifier", result->identifier);
	return std::move(result);
}

void PositionalReferenceExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("index", index);
}

unique_ptr<ParsedExpression> PositionalReferenceExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<PositionalReferenceExpression>(new PositionalReferenceExpression());
	deserializer.ReadProperty("index", result->index);
	return std::move(result);
}

void StarExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("relation_name", relation_name);
	serializer.WriteProperty("exclude_list", exclude_list);
	serializer.WriteProperty("replace_list", replace_list);
	serializer.WriteProperty("columns", columns);
	serializer.WriteOptionalProperty("expr", expr);
}

unique_ptr<ParsedExpression> StarExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<StarExpression>(new StarExpression());
	deserializer.ReadProperty("relation_name", result->relation_name);
	deserializer.ReadProperty("exclude_list", result->exclude_list);
	deserializer.ReadProperty("replace_list", result->replace_list);
	deserializer.ReadProperty("columns", result->columns);
	deserializer.ReadOptionalProperty("expr", result->expr);
	return std::move(result);
}

void SubqueryExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("subquery_type", subquery_type);
	serializer.WriteProperty("subquery", subquery);
	serializer.WriteOptionalProperty("child", child);
	serializer.WriteProperty("comparison_type", comparison_type);
}

unique_ptr<ParsedExpression> SubqueryExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<SubqueryExpression>(new SubqueryExpression());
	deserializer.ReadProperty("subquery_type", result->subquery_type);
	deserializer.ReadProperty("subquery", result->subquery);
	deserializer.ReadOptionalProperty("child", result->child);
	deserializer.ReadProperty("comparison_type", result->comparison_type);
	return std::move(result);
}

void WindowExpression::FormatSerialize(FormatSerializer &serializer) const {
	ParsedExpression::FormatSerialize(serializer);
	serializer.WriteProperty("function_name", function_name);
	serializer.WriteProperty("schema", schema);
	serializer.WriteProperty("catalog", catalog);
	serializer.WriteProperty("children", children);
	serializer.WriteProperty("partitions", partitions);
	serializer.WriteProperty("orders", orders);
	serializer.WriteProperty("start", start);
	serializer.WriteProperty("end", end);
	serializer.WriteOptionalProperty("start_expr", start_expr);
	serializer.WriteOptionalProperty("end_expr", end_expr);
	serializer.WriteOptionalProperty("offset_expr", offset_expr);
	serializer.WriteOptionalProperty("default_expr", default_expr);
	serializer.WriteProperty("ignore_nulls", ignore_nulls);
	serializer.WriteOptionalProperty("filter_expr", filter_expr);
}

unique_ptr<ParsedExpression> WindowExpression::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<WindowExpression>(new WindowExpression(deserializer.Get<ExpressionType>()));
	deserializer.ReadProperty("function_name", result->function_name);
	deserializer.ReadProperty("schema", result->schema);
	deserializer.ReadProperty("catalog", result->catalog);
	deserializer.ReadProperty("children", result->children);
	deserializer.ReadProperty("partitions", result->partitions);
	deserializer.ReadProperty("orders", result->orders);
	deserializer.ReadProperty("start", result->start);
	deserializer.ReadProperty("end", result->end);
	deserializer.ReadOptionalProperty("start_expr", result->start_expr);
	deserializer.ReadOptionalProperty("end_expr", result->end_expr);
	deserializer.ReadOptionalProperty("offset_expr", result->offset_expr);
	deserializer.ReadOptionalProperty("default_expr", result->default_expr);
	deserializer.ReadProperty("ignore_nulls", result->ignore_nulls);
	deserializer.ReadOptionalProperty("filter_expr", result->filter_expr);
	return std::move(result);
}

} // namespace duckdb
