// package: duckdb_wasm.proto
// file: query_result.proto

import * as jspb from "google-protobuf";
import * as sql_type_pb from "./sql_type_pb";

export class QueryResultColumn extends jspb.Message {
  clearNullMaskList(): void;
  getNullMaskList(): Array<boolean>;
  setNullMaskList(value: Array<boolean>): void;
  addNullMask(value: boolean, index?: number): boolean;

  clearRowsBoolList(): void;
  getRowsBoolList(): Array<boolean>;
  setRowsBoolList(value: Array<boolean>): void;
  addRowsBool(value: boolean, index?: number): boolean;

  clearRowsI32List(): void;
  getRowsI32List(): Array<number>;
  setRowsI32List(value: Array<number>): void;
  addRowsI32(value: number, index?: number): number;

  clearRowsU32List(): void;
  getRowsU32List(): Array<number>;
  setRowsU32List(value: Array<number>): void;
  addRowsU32(value: number, index?: number): number;

  clearRowsI64List(): void;
  getRowsI64List(): Array<number>;
  setRowsI64List(value: Array<number>): void;
  addRowsI64(value: number, index?: number): number;

  clearRowsU64List(): void;
  getRowsU64List(): Array<number>;
  setRowsU64List(value: Array<number>): void;
  addRowsU64(value: number, index?: number): number;

  clearRowsF32List(): void;
  getRowsF32List(): Array<number>;
  setRowsF32List(value: Array<number>): void;
  addRowsF32(value: number, index?: number): number;

  clearRowsF64List(): void;
  getRowsF64List(): Array<number>;
  setRowsF64List(value: Array<number>): void;
  addRowsF64(value: number, index?: number): number;

  clearRowsStrList(): void;
  getRowsStrList(): Array<string>;
  setRowsStrList(value: Array<string>): void;
  addRowsStr(value: string, index?: number): string;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): QueryResultColumn.AsObject;
  static toObject(includeInstance: boolean, msg: QueryResultColumn): QueryResultColumn.AsObject;
  static extensions: {[key: number]: jspb.ExtensionFieldInfo<jspb.Message>};
  static extensionsBinary: {[key: number]: jspb.ExtensionFieldBinaryInfo<jspb.Message>};
  static serializeBinaryToWriter(message: QueryResultColumn, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): QueryResultColumn;
  static deserializeBinaryFromReader(message: QueryResultColumn, reader: jspb.BinaryReader): QueryResultColumn;
}

export namespace QueryResultColumn {
  export type AsObject = {
    nullMaskList: Array<boolean>,
    rowsBoolList: Array<boolean>,
    rowsI32List: Array<number>,
    rowsU32List: Array<number>,
    rowsI64List: Array<number>,
    rowsU64List: Array<number>,
    rowsF32List: Array<number>,
    rowsF64List: Array<number>,
    rowsStrList: Array<string>,
  }
}

export class QueryResultChunk extends jspb.Message {
  getRowOffset(): number;
  setRowOffset(value: number): void;

  getRowCount(): number;
  setRowCount(value: number): void;

  clearColumnsList(): void;
  getColumnsList(): Array<QueryResultColumn>;
  setColumnsList(value: Array<QueryResultColumn>): void;
  addColumns(value?: QueryResultColumn, index?: number): QueryResultColumn;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): QueryResultChunk.AsObject;
  static toObject(includeInstance: boolean, msg: QueryResultChunk): QueryResultChunk.AsObject;
  static extensions: {[key: number]: jspb.ExtensionFieldInfo<jspb.Message>};
  static extensionsBinary: {[key: number]: jspb.ExtensionFieldBinaryInfo<jspb.Message>};
  static serializeBinaryToWriter(message: QueryResultChunk, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): QueryResultChunk;
  static deserializeBinaryFromReader(message: QueryResultChunk, reader: jspb.BinaryReader): QueryResultChunk;
}

export namespace QueryResultChunk {
  export type AsObject = {
    rowOffset: number,
    rowCount: number,
    columnsList: Array<QueryResultColumn.AsObject>,
  }
}

export class QueryResultHeader extends jspb.Message {
  getQueryId(): number;
  setQueryId(value: number): void;

  getColumnCount(): number;
  setColumnCount(value: number): void;

  getRowCount(): number;
  setRowCount(value: number): void;

  clearColumnNamesList(): void;
  getColumnNamesList(): Array<string>;
  setColumnNamesList(value: Array<string>): void;
  addColumnNames(value: string, index?: number): string;

  clearColumnSqlTypesList(): void;
  getColumnSqlTypesList(): Array<sql_type_pb.SQLType>;
  setColumnSqlTypesList(value: Array<sql_type_pb.SQLType>): void;
  addColumnSqlTypes(value?: sql_type_pb.SQLType, index?: number): sql_type_pb.SQLType;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): QueryResultHeader.AsObject;
  static toObject(includeInstance: boolean, msg: QueryResultHeader): QueryResultHeader.AsObject;
  static extensions: {[key: number]: jspb.ExtensionFieldInfo<jspb.Message>};
  static extensionsBinary: {[key: number]: jspb.ExtensionFieldBinaryInfo<jspb.Message>};
  static serializeBinaryToWriter(message: QueryResultHeader, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): QueryResultHeader;
  static deserializeBinaryFromReader(message: QueryResultHeader, reader: jspb.BinaryReader): QueryResultHeader;
}

export namespace QueryResultHeader {
  export type AsObject = {
    queryId: number,
    columnCount: number,
    rowCount: number,
    columnNamesList: Array<string>,
    columnSqlTypesList: Array<sql_type_pb.SQLType.AsObject>,
  }
}

