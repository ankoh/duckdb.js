// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: query_plan.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_query_5fplan_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_query_5fplan_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_query_5fplan_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_query_5fplan_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
namespace duckdb_webapi {
namespace proto {
class QueryPlan;
class QueryPlanDefaultTypeInternal;
extern QueryPlanDefaultTypeInternal _QueryPlan_default_instance_;
}  // namespace proto
}  // namespace duckdb_webapi
PROTOBUF_NAMESPACE_OPEN
template<> ::duckdb_webapi::proto::QueryPlan* Arena::CreateMaybeMessage<::duckdb_webapi::proto::QueryPlan>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace duckdb_webapi {
namespace proto {

enum LogicalOperatorType : int {
  OP_INVALID = 0,
  OP_PROJECTION = 1,
  OP_FILTER = 2,
  OP_AGGREGATE_AND_GROUP_BY = 3,
  OP_WINDOW = 4,
  OP_UNNEST = 5,
  OP_LIMIT = 6,
  OP_ORDER_BY = 7,
  OP_TOP_N = 8,
  OP_COPY_FROM_FILE = 9,
  OP_COPY_TO_FILE = 10,
  OP_DISTINCT = 11,
  OP_INDEX_SCAN = 12,
  OP_GET = 13,
  OP_CHUNK_GET = 14,
  OP_DELIM_GET = 15,
  OP_EXPRESSION_GET = 16,
  OP_TABLE_FUNCTION = 17,
  OP_EMPTY_RESULT = 18,
  OP_CTE_REF = 19,
  OP_JOIN = 20,
  OP_DELIM_JOIN = 21,
  OP_COMPARISON_JOIN = 22,
  OP_ANY_JOIN = 23,
  OP_CROSS_PRODUCT = 24,
  OP_UNION = 25,
  OP_EXCEPT = 26,
  OP_INTERSECT = 27,
  OP_RECURSIVE_CTE = 28,
  OP_INSERT = 29,
  OP_DELETE = 30,
  OP_UPDATE = 31,
  OP_ALTER = 32,
  OP_CREATE_TABLE = 33,
  OP_CREATE_INDEX = 34,
  OP_CREATE_SEQUENCE = 35,
  OP_CREATE_VIEW = 36,
  OP_CREATE_SCHEMA = 37,
  OP_DROP = 38,
  OP_PRAGMA = 39,
  OP_TRANSACTION = 40,
  OP_EXPLAIN = 41,
  OP_PREPARE = 42,
  OP_EXECUTE = 43,
  OP_VACUUM = 44,
  LogicalOperatorType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  LogicalOperatorType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool LogicalOperatorType_IsValid(int value);
constexpr LogicalOperatorType LogicalOperatorType_MIN = OP_INVALID;
constexpr LogicalOperatorType LogicalOperatorType_MAX = OP_VACUUM;
constexpr int LogicalOperatorType_ARRAYSIZE = LogicalOperatorType_MAX + 1;

const std::string& LogicalOperatorType_Name(LogicalOperatorType value);
template<typename T>
inline const std::string& LogicalOperatorType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, LogicalOperatorType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function LogicalOperatorType_Name.");
  return LogicalOperatorType_Name(static_cast<LogicalOperatorType>(enum_t_value));
}
bool LogicalOperatorType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LogicalOperatorType* value);
// ===================================================================

class QueryPlan PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::MessageLite /* @@protoc_insertion_point(class_definition:duckdb_webapi.proto.QueryPlan) */ {
 public:
  inline QueryPlan() : QueryPlan(nullptr) {}
  virtual ~QueryPlan();

  QueryPlan(const QueryPlan& from);
  QueryPlan(QueryPlan&& from) noexcept
    : QueryPlan() {
    *this = ::std::move(from);
  }

  inline QueryPlan& operator=(const QueryPlan& from) {
    CopyFrom(from);
    return *this;
  }
  inline QueryPlan& operator=(QueryPlan&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const QueryPlan& default_instance();

  static inline const QueryPlan* internal_default_instance() {
    return reinterpret_cast<const QueryPlan*>(
               &_QueryPlan_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(QueryPlan& a, QueryPlan& b) {
    a.Swap(&b);
  }
  inline void Swap(QueryPlan* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(QueryPlan* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline QueryPlan* New() const final {
    return CreateMaybeMessage<QueryPlan>(nullptr);
  }

  QueryPlan* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<QueryPlan>(arena);
  }
  void CheckTypeAndMergeFrom(const ::PROTOBUF_NAMESPACE_ID::MessageLite& from)
    final;
  void CopyFrom(const QueryPlan& from);
  void MergeFrom(const QueryPlan& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  void DiscardUnknownFields();
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(QueryPlan* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "duckdb_webapi.proto.QueryPlan";
  }
  protected:
  explicit QueryPlan(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  std::string GetTypeName() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kOperatorChildrenFieldNumber = 1,
    kOperatorChildOffsetsFieldNumber = 2,
    kOperatorTypesFieldNumber = 3,
  };
  // repeated uint64 operator_children = 1;
  int operator_children_size() const;
  private:
  int _internal_operator_children_size() const;
  public:
  void clear_operator_children();
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_operator_children(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >&
      _internal_operator_children() const;
  void _internal_add_operator_children(::PROTOBUF_NAMESPACE_ID::uint64 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >*
      _internal_mutable_operator_children();
  public:
  ::PROTOBUF_NAMESPACE_ID::uint64 operator_children(int index) const;
  void set_operator_children(int index, ::PROTOBUF_NAMESPACE_ID::uint64 value);
  void add_operator_children(::PROTOBUF_NAMESPACE_ID::uint64 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >&
      operator_children() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >*
      mutable_operator_children();

  // repeated uint64 operator_child_offsets = 2;
  int operator_child_offsets_size() const;
  private:
  int _internal_operator_child_offsets_size() const;
  public:
  void clear_operator_child_offsets();
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_operator_child_offsets(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >&
      _internal_operator_child_offsets() const;
  void _internal_add_operator_child_offsets(::PROTOBUF_NAMESPACE_ID::uint64 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >*
      _internal_mutable_operator_child_offsets();
  public:
  ::PROTOBUF_NAMESPACE_ID::uint64 operator_child_offsets(int index) const;
  void set_operator_child_offsets(int index, ::PROTOBUF_NAMESPACE_ID::uint64 value);
  void add_operator_child_offsets(::PROTOBUF_NAMESPACE_ID::uint64 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >&
      operator_child_offsets() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >*
      mutable_operator_child_offsets();

  // repeated .duckdb_webapi.proto.LogicalOperatorType operator_types = 3;
  int operator_types_size() const;
  private:
  int _internal_operator_types_size() const;
  public:
  void clear_operator_types();
  private:
  ::duckdb_webapi::proto::LogicalOperatorType _internal_operator_types(int index) const;
  void _internal_add_operator_types(::duckdb_webapi::proto::LogicalOperatorType value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>* _internal_mutable_operator_types();
  public:
  ::duckdb_webapi::proto::LogicalOperatorType operator_types(int index) const;
  void set_operator_types(int index, ::duckdb_webapi::proto::LogicalOperatorType value);
  void add_operator_types(::duckdb_webapi::proto::LogicalOperatorType value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>& operator_types() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>* mutable_operator_types();

  // @@protoc_insertion_point(class_scope:duckdb_webapi.proto.QueryPlan)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 > operator_children_;
  mutable std::atomic<int> _operator_children_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 > operator_child_offsets_;
  mutable std::atomic<int> _operator_child_offsets_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<int> operator_types_;
  mutable std::atomic<int> _operator_types_cached_byte_size_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_query_5fplan_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// QueryPlan

// repeated uint64 operator_children = 1;
inline int QueryPlan::_internal_operator_children_size() const {
  return operator_children_.size();
}
inline int QueryPlan::operator_children_size() const {
  return _internal_operator_children_size();
}
inline void QueryPlan::clear_operator_children() {
  operator_children_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 QueryPlan::_internal_operator_children(int index) const {
  return operator_children_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 QueryPlan::operator_children(int index) const {
  // @@protoc_insertion_point(field_get:duckdb_webapi.proto.QueryPlan.operator_children)
  return _internal_operator_children(index);
}
inline void QueryPlan::set_operator_children(int index, ::PROTOBUF_NAMESPACE_ID::uint64 value) {
  operator_children_.Set(index, value);
  // @@protoc_insertion_point(field_set:duckdb_webapi.proto.QueryPlan.operator_children)
}
inline void QueryPlan::_internal_add_operator_children(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  operator_children_.Add(value);
}
inline void QueryPlan::add_operator_children(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_add_operator_children(value);
  // @@protoc_insertion_point(field_add:duckdb_webapi.proto.QueryPlan.operator_children)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >&
QueryPlan::_internal_operator_children() const {
  return operator_children_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >&
QueryPlan::operator_children() const {
  // @@protoc_insertion_point(field_list:duckdb_webapi.proto.QueryPlan.operator_children)
  return _internal_operator_children();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >*
QueryPlan::_internal_mutable_operator_children() {
  return &operator_children_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >*
QueryPlan::mutable_operator_children() {
  // @@protoc_insertion_point(field_mutable_list:duckdb_webapi.proto.QueryPlan.operator_children)
  return _internal_mutable_operator_children();
}

// repeated uint64 operator_child_offsets = 2;
inline int QueryPlan::_internal_operator_child_offsets_size() const {
  return operator_child_offsets_.size();
}
inline int QueryPlan::operator_child_offsets_size() const {
  return _internal_operator_child_offsets_size();
}
inline void QueryPlan::clear_operator_child_offsets() {
  operator_child_offsets_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 QueryPlan::_internal_operator_child_offsets(int index) const {
  return operator_child_offsets_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 QueryPlan::operator_child_offsets(int index) const {
  // @@protoc_insertion_point(field_get:duckdb_webapi.proto.QueryPlan.operator_child_offsets)
  return _internal_operator_child_offsets(index);
}
inline void QueryPlan::set_operator_child_offsets(int index, ::PROTOBUF_NAMESPACE_ID::uint64 value) {
  operator_child_offsets_.Set(index, value);
  // @@protoc_insertion_point(field_set:duckdb_webapi.proto.QueryPlan.operator_child_offsets)
}
inline void QueryPlan::_internal_add_operator_child_offsets(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  operator_child_offsets_.Add(value);
}
inline void QueryPlan::add_operator_child_offsets(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_add_operator_child_offsets(value);
  // @@protoc_insertion_point(field_add:duckdb_webapi.proto.QueryPlan.operator_child_offsets)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >&
QueryPlan::_internal_operator_child_offsets() const {
  return operator_child_offsets_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >&
QueryPlan::operator_child_offsets() const {
  // @@protoc_insertion_point(field_list:duckdb_webapi.proto.QueryPlan.operator_child_offsets)
  return _internal_operator_child_offsets();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >*
QueryPlan::_internal_mutable_operator_child_offsets() {
  return &operator_child_offsets_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint64 >*
QueryPlan::mutable_operator_child_offsets() {
  // @@protoc_insertion_point(field_mutable_list:duckdb_webapi.proto.QueryPlan.operator_child_offsets)
  return _internal_mutable_operator_child_offsets();
}

// repeated .duckdb_webapi.proto.LogicalOperatorType operator_types = 3;
inline int QueryPlan::_internal_operator_types_size() const {
  return operator_types_.size();
}
inline int QueryPlan::operator_types_size() const {
  return _internal_operator_types_size();
}
inline void QueryPlan::clear_operator_types() {
  operator_types_.Clear();
}
inline ::duckdb_webapi::proto::LogicalOperatorType QueryPlan::_internal_operator_types(int index) const {
  return static_cast< ::duckdb_webapi::proto::LogicalOperatorType >(operator_types_.Get(index));
}
inline ::duckdb_webapi::proto::LogicalOperatorType QueryPlan::operator_types(int index) const {
  // @@protoc_insertion_point(field_get:duckdb_webapi.proto.QueryPlan.operator_types)
  return _internal_operator_types(index);
}
inline void QueryPlan::set_operator_types(int index, ::duckdb_webapi::proto::LogicalOperatorType value) {
  operator_types_.Set(index, value);
  // @@protoc_insertion_point(field_set:duckdb_webapi.proto.QueryPlan.operator_types)
}
inline void QueryPlan::_internal_add_operator_types(::duckdb_webapi::proto::LogicalOperatorType value) {
  operator_types_.Add(value);
}
inline void QueryPlan::add_operator_types(::duckdb_webapi::proto::LogicalOperatorType value) {
  // @@protoc_insertion_point(field_add:duckdb_webapi.proto.QueryPlan.operator_types)
  _internal_add_operator_types(value);
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>&
QueryPlan::operator_types() const {
  // @@protoc_insertion_point(field_list:duckdb_webapi.proto.QueryPlan.operator_types)
  return operator_types_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>*
QueryPlan::_internal_mutable_operator_types() {
  return &operator_types_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<int>*
QueryPlan::mutable_operator_types() {
  // @@protoc_insertion_point(field_mutable_list:duckdb_webapi.proto.QueryPlan.operator_types)
  return _internal_mutable_operator_types();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace duckdb_webapi

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::duckdb_webapi::proto::LogicalOperatorType> : ::std::true_type {};

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_query_5fplan_2eproto