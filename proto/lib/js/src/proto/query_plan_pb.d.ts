// package: duckdb_webapi.proto
// file: query_plan.proto

import * as jspb from "google-protobuf";

export class QueryPlan extends jspb.Message {
  clearOperatorChildrenList(): void;
  getOperatorChildrenList(): Array<number>;
  setOperatorChildrenList(value: Array<number>): void;
  addOperatorChildren(value: number, index?: number): number;

  clearOperatorChildOffsetsList(): void;
  getOperatorChildOffsetsList(): Array<number>;
  setOperatorChildOffsetsList(value: Array<number>): void;
  addOperatorChildOffsets(value: number, index?: number): number;

  clearOperatorTypesList(): void;
  getOperatorTypesList(): Array<LogicalOperatorTypeMap[keyof LogicalOperatorTypeMap]>;
  setOperatorTypesList(value: Array<LogicalOperatorTypeMap[keyof LogicalOperatorTypeMap]>): void;
  addOperatorTypes(value: LogicalOperatorTypeMap[keyof LogicalOperatorTypeMap], index?: number): LogicalOperatorTypeMap[keyof LogicalOperatorTypeMap];

  serializeBinary(): Uint8Array;
  toObject(includeInstance?: boolean): QueryPlan.AsObject;
  static toObject(includeInstance: boolean, msg: QueryPlan): QueryPlan.AsObject;
  static extensions: {[key: number]: jspb.ExtensionFieldInfo<jspb.Message>};
  static extensionsBinary: {[key: number]: jspb.ExtensionFieldBinaryInfo<jspb.Message>};
  static serializeBinaryToWriter(message: QueryPlan, writer: jspb.BinaryWriter): void;
  static deserializeBinary(bytes: Uint8Array): QueryPlan;
  static deserializeBinaryFromReader(message: QueryPlan, reader: jspb.BinaryReader): QueryPlan;
}

export namespace QueryPlan {
  export type AsObject = {
    operatorChildrenList: Array<number>,
    operatorChildOffsetsList: Array<number>,
    operatorTypesList: Array<LogicalOperatorTypeMap[keyof LogicalOperatorTypeMap]>,
  }
}

export interface LogicalOperatorTypeMap {
  OP_INVALID: 0;
  OP_PROJECTION: 1;
  OP_FILTER: 2;
  OP_AGGREGATE_AND_GROUP_BY: 3;
  OP_WINDOW: 4;
  OP_UNNEST: 5;
  OP_LIMIT: 6;
  OP_ORDER_BY: 7;
  OP_TOP_N: 8;
  OP_COPY_FROM_FILE: 9;
  OP_COPY_TO_FILE: 10;
  OP_DISTINCT: 11;
  OP_INDEX_SCAN: 12;
  OP_GET: 13;
  OP_CHUNK_GET: 14;
  OP_DELIM_GET: 15;
  OP_EXPRESSION_GET: 16;
  OP_TABLE_FUNCTION: 17;
  OP_EMPTY_RESULT: 18;
  OP_CTE_REF: 19;
  OP_JOIN: 20;
  OP_DELIM_JOIN: 21;
  OP_COMPARISON_JOIN: 22;
  OP_ANY_JOIN: 23;
  OP_CROSS_PRODUCT: 24;
  OP_UNION: 25;
  OP_EXCEPT: 26;
  OP_INTERSECT: 27;
  OP_RECURSIVE_CTE: 28;
  OP_INSERT: 29;
  OP_DELETE: 30;
  OP_UPDATE: 31;
  OP_ALTER: 32;
  OP_CREATE_TABLE: 33;
  OP_CREATE_INDEX: 34;
  OP_CREATE_SEQUENCE: 35;
  OP_CREATE_VIEW: 36;
  OP_CREATE_SCHEMA: 37;
  OP_DROP: 38;
  OP_PRAGMA: 39;
  OP_TRANSACTION: 40;
  OP_EXPLAIN: 41;
  OP_PREPARE: 42;
  OP_EXECUTE: 43;
  OP_VACUUM: 44;
}

export const LogicalOperatorType: LogicalOperatorTypeMap;

