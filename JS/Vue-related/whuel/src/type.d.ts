declare interface ISub {
  update(): void;
}

declare interface IData {
  [key: string]: number | string | boolean | undefined | null | Object | Symbol;
}
