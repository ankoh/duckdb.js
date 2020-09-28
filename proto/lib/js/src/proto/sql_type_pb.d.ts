// package: duckdb_webapi.proto
// file: sql_type.proto

import * as jspb from "google-protobuf";

export class SQLType extends jspb.Message {
  getTypeId(): SQLTypeIDMap[keyof SQLTypeIDMap];
  setTypeId(value: SQLTypeIDMap[keyof SQLTypeIDMap]): void;

  getWidth(): number;
  setWidth(value: number): void;

  getScale(): number;
  setScale(value: number): void;

  getCollation(): string;
  setCollation(value: string): void;

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): SQLType.AsObject;
  static toObject(includeInstance: boolean, msg: SQLType): SQLType.AsObject;
  static extensions: {[key: number]: jspb.ExtensionFieldInfo<jspb.Message>};
  static extensionsBinary: {[key: number]: jspb.ExtensionFieldBinaryInfo<jspb.Message>};
  static serializeBinaryToWriter(message: SQLType, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): SQLType;
  static deserializeBinaryFromReader(message: SQLType, reader: jspb.BinaryReader): SQLType;
}

export namespace SQLType {
  export type AsObject = {
    typeId: SQLTypeIDMap[keyof SQLTypeIDMap],
    width: number,
    scale: number,
    collation: string,
  }
}

export interface SQLTypeIDMap {
  SQL_INVALID: 0;
  SQL_NULL: 1;
  SQL_UNKNOWN: 2;
  SQL_ANY: 3;
  SQL_BOOLEAN: 10;
  SQL_TINYINT: 11;
  SQL_SMALLINT: 12;
  SQL_INTEGER: 13;
  SQL_BIGINT: 14;
  SQL_DATE: 15;
  SQL_TIME: 16;
  SQL_TIMESTAMP: 17;
  SQL_FLOAT: 18;
  SQL_DOUBLE: 19;
  SQL_DECIMAL: 20;
  SQL_CHAR: 21;
  SQL_VARCHAR: 22;
  SQL_VARBINARY: 23;
  SQL_BLOB: 24;
  SQL_STRUCT: 100;
  SQL_LIST: 101;
}

export const SQLTypeID: SQLTypeIDMap;

