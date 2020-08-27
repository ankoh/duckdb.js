// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: api.proto

#include "api.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace duckdb_wasm {
namespace proto {
class FormattedTextDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<FormattedText> _instance;
} _FormattedText_default_instance_;
class RawDataDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<RawData> _instance;
} _RawData_default_instance_;
}  // namespace proto
}  // namespace duckdb_wasm
static void InitDefaultsscc_info_FormattedText_api_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::duckdb_wasm::proto::_FormattedText_default_instance_;
    new (ptr) ::duckdb_wasm::proto::FormattedText();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_FormattedText_api_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_FormattedText_api_2eproto}, {}};

static void InitDefaultsscc_info_RawData_api_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::duckdb_wasm::proto::_RawData_default_instance_;
    new (ptr) ::duckdb_wasm::proto::RawData();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_RawData_api_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_RawData_api_2eproto}, {}};

namespace duckdb_wasm {
namespace proto {
bool StatusCode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

static ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std::string> StatusCode_strings[2] = {};

static const char StatusCode_names[] =
  "ERROR"
  "SUCCESS";

static const ::PROTOBUF_NAMESPACE_ID::internal::EnumEntry StatusCode_entries[] = {
  { {StatusCode_names + 0, 5}, 1 },
  { {StatusCode_names + 5, 7}, 0 },
};

static const int StatusCode_entries_by_number[] = {
  1, // 0 -> SUCCESS
  0, // 1 -> ERROR
};

const std::string& StatusCode_Name(
    StatusCode value) {
  static const bool dummy =
      ::PROTOBUF_NAMESPACE_ID::internal::InitializeEnumStrings(
          StatusCode_entries,
          StatusCode_entries_by_number,
          2, StatusCode_strings);
  (void) dummy;
  int idx = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumName(
      StatusCode_entries,
      StatusCode_entries_by_number,
      2, value);
  return idx == -1 ? ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString() :
                     StatusCode_strings[idx].get();
}
bool StatusCode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, StatusCode* value) {
  int int_value;
  bool success = ::PROTOBUF_NAMESPACE_ID::internal::LookUpEnumValue(
      StatusCode_entries, 2, name, &int_value);
  if (success) {
    *value = static_cast<StatusCode>(int_value);
  }
  return success;
}

// ===================================================================

class FormattedText::_Internal {
 public:
};

FormattedText::FormattedText(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:duckdb_wasm.proto.FormattedText)
}
FormattedText::FormattedText(const FormattedText& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite() {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  text_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_text().empty()) {
    text_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_text(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:duckdb_wasm.proto.FormattedText)
}

void FormattedText::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_FormattedText_api_2eproto.base);
  text_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

FormattedText::~FormattedText() {
  // @@protoc_insertion_point(destructor:duckdb_wasm.proto.FormattedText)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void FormattedText::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  text_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void FormattedText::ArenaDtor(void* object) {
  FormattedText* _this = reinterpret_cast< FormattedText* >(object);
  (void)_this;
}
void FormattedText::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void FormattedText::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const FormattedText& FormattedText::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_FormattedText_api_2eproto.base);
  return *internal_default_instance();
}


void FormattedText::Clear() {
// @@protoc_insertion_point(message_clear_start:duckdb_wasm.proto.FormattedText)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  text_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<std::string>();
}

const char* FormattedText::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string text = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_text();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, nullptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* FormattedText::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:duckdb_wasm.proto.FormattedText)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string text = 1;
  if (this->text().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_text().data(), static_cast<int>(this->_internal_text().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "duckdb_wasm.proto.FormattedText.text");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_text(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:duckdb_wasm.proto.FormattedText)
  return target;
}

size_t FormattedText::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:duckdb_wasm.proto.FormattedText)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string text = 1;
  if (this->text().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_text());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void FormattedText::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const FormattedText*>(
      &from));
}

void FormattedText::MergeFrom(const FormattedText& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:duckdb_wasm.proto.FormattedText)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.text().size() > 0) {
    _internal_set_text(from._internal_text());
  }
}

void FormattedText::CopyFrom(const FormattedText& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:duckdb_wasm.proto.FormattedText)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FormattedText::IsInitialized() const {
  return true;
}

void FormattedText::InternalSwap(FormattedText* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  text_.Swap(&other->text_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

std::string FormattedText::GetTypeName() const {
  return "duckdb_wasm.proto.FormattedText";
}


// ===================================================================

class RawData::_Internal {
 public:
};

RawData::RawData(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:duckdb_wasm.proto.RawData)
}
RawData::RawData(const RawData& from)
  : ::PROTOBUF_NAMESPACE_ID::MessageLite() {
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_data().empty()) {
    data_.SetLite(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_data(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:duckdb_wasm.proto.RawData)
}

void RawData::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_RawData_api_2eproto.base);
  data_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

RawData::~RawData() {
  // @@protoc_insertion_point(destructor:duckdb_wasm.proto.RawData)
  SharedDtor();
  _internal_metadata_.Delete<std::string>();
}

void RawData::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  data_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void RawData::ArenaDtor(void* object) {
  RawData* _this = reinterpret_cast< RawData* >(object);
  (void)_this;
}
void RawData::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RawData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const RawData& RawData::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_RawData_api_2eproto.base);
  return *internal_default_instance();
}


void RawData::Clear() {
// @@protoc_insertion_point(message_clear_start:duckdb_wasm.proto.RawData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<std::string>();
}

const char* RawData::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // bytes data = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_data();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<std::string>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RawData::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:duckdb_wasm.proto.RawData)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes data = 1;
  if (this->data().size() > 0) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = stream->WriteRaw(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).data(),
        static_cast<int>(_internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:duckdb_wasm.proto.RawData)
  return target;
}

size_t RawData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:duckdb_wasm.proto.RawData)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes data = 1;
  if (this->data().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_data());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    total_size += _internal_metadata_.unknown_fields<std::string>(::PROTOBUF_NAMESPACE_ID::internal::GetEmptyString).size();
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RawData::CheckTypeAndMergeFrom(
    const ::PROTOBUF_NAMESPACE_ID::MessageLite& from) {
  MergeFrom(*::PROTOBUF_NAMESPACE_ID::internal::DownCast<const RawData*>(
      &from));
}

void RawData::MergeFrom(const RawData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:duckdb_wasm.proto.RawData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<std::string>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.data().size() > 0) {
    _internal_set_data(from._internal_data());
  }
}

void RawData::CopyFrom(const RawData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:duckdb_wasm.proto.RawData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RawData::IsInitialized() const {
  return true;
}

void RawData::InternalSwap(RawData* other) {
  using std::swap;
  _internal_metadata_.Swap<std::string>(&other->_internal_metadata_);
  data_.Swap(&other->data_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

std::string RawData::GetTypeName() const {
  return "duckdb_wasm.proto.RawData";
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace duckdb_wasm
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::duckdb_wasm::proto::FormattedText* Arena::CreateMaybeMessage< ::duckdb_wasm::proto::FormattedText >(Arena* arena) {
  return Arena::CreateMessageInternal< ::duckdb_wasm::proto::FormattedText >(arena);
}
template<> PROTOBUF_NOINLINE ::duckdb_wasm::proto::RawData* Arena::CreateMaybeMessage< ::duckdb_wasm::proto::RawData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::duckdb_wasm::proto::RawData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
