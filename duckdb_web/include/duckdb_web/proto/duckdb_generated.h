// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DUCKDB_DUCKDB_PROTO_H_
#define FLATBUFFERS_GENERATED_DUCKDB_DUCKDB_PROTO_H_

#include "flatbuffers/flatbuffers.h"

namespace duckdb {
namespace proto {

struct DuckDBDate;

struct DuckDBTime;

struct DuckDBTimestamp;

struct DuckDBColumn;

struct DuckDBResult;

enum class DuckDBType : uint8_t {
  DUCKDB_TYPE_INVALID = 0,
  DUCKDB_TYPE_BOOLEAN = 1,
  DUCKDB_TYPE_TINYINT = 2,
  DUCKDB_TYPE_SMALLINT = 3,
  DUCKDB_TYPE_INTEGER = 4,
  DUCKDB_TYPE_BIGINT = 5,
  DUCKDB_TYPE_FLOAT = 6,
  DUCKDB_TYPE_DOUBLE = 7,
  DUCKDB_TYPE_TIMESTAMP = 8,
  DUCKDB_TYPE_DATE = 9,
  DUCKDB_TYPE_TIME = 10,
  DUCKDB_TYPE_VARCHAR = 11,
  MIN = DUCKDB_TYPE_INVALID,
  MAX = DUCKDB_TYPE_VARCHAR
};

inline const DuckDBType (&EnumValuesDuckDBType())[12] {
  static const DuckDBType values[] = {
    DuckDBType::DUCKDB_TYPE_INVALID,
    DuckDBType::DUCKDB_TYPE_BOOLEAN,
    DuckDBType::DUCKDB_TYPE_TINYINT,
    DuckDBType::DUCKDB_TYPE_SMALLINT,
    DuckDBType::DUCKDB_TYPE_INTEGER,
    DuckDBType::DUCKDB_TYPE_BIGINT,
    DuckDBType::DUCKDB_TYPE_FLOAT,
    DuckDBType::DUCKDB_TYPE_DOUBLE,
    DuckDBType::DUCKDB_TYPE_TIMESTAMP,
    DuckDBType::DUCKDB_TYPE_DATE,
    DuckDBType::DUCKDB_TYPE_TIME,
    DuckDBType::DUCKDB_TYPE_VARCHAR
  };
  return values;
}

inline const char * const *EnumNamesDuckDBType() {
  static const char * const names[] = {
    "DUCKDB_TYPE_INVALID",
    "DUCKDB_TYPE_BOOLEAN",
    "DUCKDB_TYPE_TINYINT",
    "DUCKDB_TYPE_SMALLINT",
    "DUCKDB_TYPE_INTEGER",
    "DUCKDB_TYPE_BIGINT",
    "DUCKDB_TYPE_FLOAT",
    "DUCKDB_TYPE_DOUBLE",
    "DUCKDB_TYPE_TIMESTAMP",
    "DUCKDB_TYPE_DATE",
    "DUCKDB_TYPE_TIME",
    "DUCKDB_TYPE_VARCHAR",
    nullptr
  };
  return names;
}

inline const char *EnumNameDuckDBType(DuckDBType e) {
  if (e < DuckDBType::DUCKDB_TYPE_INVALID || e > DuckDBType::DUCKDB_TYPE_VARCHAR) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesDuckDBType()[index];
}

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) DuckDBDate FLATBUFFERS_FINAL_CLASS {
 private:
  int32_t year_;
  int8_t month_;
  int8_t day_;
  int16_t padding0__;

 public:
  DuckDBDate() {
    memset(static_cast<void *>(this), 0, sizeof(DuckDBDate));
  }
  DuckDBDate(int32_t _year, int8_t _month, int8_t _day)
      : year_(flatbuffers::EndianScalar(_year)),
        month_(flatbuffers::EndianScalar(_month)),
        day_(flatbuffers::EndianScalar(_day)),
        padding0__(0) {
    (void)padding0__;
  }
  int32_t year() const {
    return flatbuffers::EndianScalar(year_);
  }
  int8_t month() const {
    return flatbuffers::EndianScalar(month_);
  }
  int8_t day() const {
    return flatbuffers::EndianScalar(day_);
  }
};
FLATBUFFERS_STRUCT_END(DuckDBDate, 8);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(2) DuckDBTime FLATBUFFERS_FINAL_CLASS {
 private:
  int8_t hour_;
  int8_t min_;
  int8_t sec_;
  int8_t padding0__;
  int16_t msec_;

 public:
  DuckDBTime() {
    memset(static_cast<void *>(this), 0, sizeof(DuckDBTime));
  }
  DuckDBTime(int8_t _hour, int8_t _min, int8_t _sec, int16_t _msec)
      : hour_(flatbuffers::EndianScalar(_hour)),
        min_(flatbuffers::EndianScalar(_min)),
        sec_(flatbuffers::EndianScalar(_sec)),
        padding0__(0),
        msec_(flatbuffers::EndianScalar(_msec)) {
    (void)padding0__;
  }
  int8_t hour() const {
    return flatbuffers::EndianScalar(hour_);
  }
  int8_t min() const {
    return flatbuffers::EndianScalar(min_);
  }
  int8_t sec() const {
    return flatbuffers::EndianScalar(sec_);
  }
  int16_t msec() const {
    return flatbuffers::EndianScalar(msec_);
  }
};
FLATBUFFERS_STRUCT_END(DuckDBTime, 6);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) DuckDBTimestamp FLATBUFFERS_FINAL_CLASS {
 private:
  DuckDBDate date_;
  DuckDBTime time_;
  int16_t padding0__;

 public:
  DuckDBTimestamp() {
    memset(static_cast<void *>(this), 0, sizeof(DuckDBTimestamp));
  }
  DuckDBTimestamp(const DuckDBDate &_date, const DuckDBTime &_time)
      : date_(_date),
        time_(_time),
        padding0__(0) {
    (void)padding0__;
  }
  const DuckDBDate &date() const {
    return date_;
  }
  const DuckDBTime &time() const {
    return time_;
  }
};
FLATBUFFERS_STRUCT_END(DuckDBTimestamp, 16);

struct DuckDBColumn FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_DATA = 4,
    VT_NULLMASK = 6,
    VT_TYPE = 8,
    VT_NAME = 10
  };
  const flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  const flatbuffers::Vector<uint8_t> *nullmask() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_NULLMASK);
  }
  DuckDBType type() const {
    return static_cast<DuckDBType>(GetField<uint8_t>(VT_TYPE, 0));
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_DATA) &&
           verifier.VerifyVector(data()) &&
           VerifyOffset(verifier, VT_NULLMASK) &&
           verifier.VerifyVector(nullmask()) &&
           VerifyField<uint8_t>(verifier, VT_TYPE) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           verifier.EndTable();
  }
};

struct DuckDBColumnBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(DuckDBColumn::VT_DATA, data);
  }
  void add_nullmask(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> nullmask) {
    fbb_.AddOffset(DuckDBColumn::VT_NULLMASK, nullmask);
  }
  void add_type(DuckDBType type) {
    fbb_.AddElement<uint8_t>(DuckDBColumn::VT_TYPE, static_cast<uint8_t>(type), 0);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(DuckDBColumn::VT_NAME, name);
  }
  explicit DuckDBColumnBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DuckDBColumnBuilder &operator=(const DuckDBColumnBuilder &);
  flatbuffers::Offset<DuckDBColumn> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DuckDBColumn>(end);
    return o;
  }
};

inline flatbuffers::Offset<DuckDBColumn> CreateDuckDBColumn(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> nullmask = 0,
    DuckDBType type = DuckDBType::DUCKDB_TYPE_INVALID,
    flatbuffers::Offset<flatbuffers::String> name = 0) {
  DuckDBColumnBuilder builder_(_fbb);
  builder_.add_name(name);
  builder_.add_nullmask(nullmask);
  builder_.add_data(data);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<DuckDBColumn> CreateDuckDBColumnDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint8_t> *data = nullptr,
    const std::vector<uint8_t> *nullmask = nullptr,
    DuckDBType type = DuckDBType::DUCKDB_TYPE_INVALID,
    const char *name = nullptr) {
  auto data__ = data ? _fbb.CreateVector<uint8_t>(*data) : 0;
  auto nullmask__ = nullmask ? _fbb.CreateVector<uint8_t>(*nullmask) : 0;
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return duckdb::proto::CreateDuckDBColumn(
      _fbb,
      data__,
      nullmask__,
      type,
      name__);
}

struct DuckDBResult FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_COLUMNS = 4,
    VT_ROWS = 6,
    VT_ERROR_MESSAGE = 8
  };
  const flatbuffers::Vector<flatbuffers::Offset<DuckDBColumn>> *columns() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<DuckDBColumn>> *>(VT_COLUMNS);
  }
  uint32_t rows() const {
    return GetField<uint32_t>(VT_ROWS, 0);
  }
  const flatbuffers::String *error_message() const {
    return GetPointer<const flatbuffers::String *>(VT_ERROR_MESSAGE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_COLUMNS) &&
           verifier.VerifyVector(columns()) &&
           verifier.VerifyVectorOfTables(columns()) &&
           VerifyField<uint32_t>(verifier, VT_ROWS) &&
           VerifyOffset(verifier, VT_ERROR_MESSAGE) &&
           verifier.VerifyString(error_message()) &&
           verifier.EndTable();
  }
};

struct DuckDBResultBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_columns(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DuckDBColumn>>> columns) {
    fbb_.AddOffset(DuckDBResult::VT_COLUMNS, columns);
  }
  void add_rows(uint32_t rows) {
    fbb_.AddElement<uint32_t>(DuckDBResult::VT_ROWS, rows, 0);
  }
  void add_error_message(flatbuffers::Offset<flatbuffers::String> error_message) {
    fbb_.AddOffset(DuckDBResult::VT_ERROR_MESSAGE, error_message);
  }
  explicit DuckDBResultBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  DuckDBResultBuilder &operator=(const DuckDBResultBuilder &);
  flatbuffers::Offset<DuckDBResult> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DuckDBResult>(end);
    return o;
  }
};

inline flatbuffers::Offset<DuckDBResult> CreateDuckDBResult(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<DuckDBColumn>>> columns = 0,
    uint32_t rows = 0,
    flatbuffers::Offset<flatbuffers::String> error_message = 0) {
  DuckDBResultBuilder builder_(_fbb);
  builder_.add_error_message(error_message);
  builder_.add_rows(rows);
  builder_.add_columns(columns);
  return builder_.Finish();
}

inline flatbuffers::Offset<DuckDBResult> CreateDuckDBResultDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<DuckDBColumn>> *columns = nullptr,
    uint32_t rows = 0,
    const char *error_message = nullptr) {
  auto columns__ = columns ? _fbb.CreateVector<flatbuffers::Offset<DuckDBColumn>>(*columns) : 0;
  auto error_message__ = error_message ? _fbb.CreateString(error_message) : 0;
  return duckdb::proto::CreateDuckDBResult(
      _fbb,
      columns__,
      rows,
      error_message__);
}

}  // namespace proto
}  // namespace duckdb

#endif  // FLATBUFFERS_GENERATED_DUCKDB_DUCKDB_PROTO_H_
