class Watcher {
  private cb: Function;
  private vm: IData;
  private expOrFn: Function;
  private depIds: object = {};
  private getter: Function;

  constructor(vm: IData, expOrFn: Function, cb: Function) {
    this.cb = cb;
    this.vm = vm;
    this.expOrFn = expOrFn;

    if (typeof expOrFn === 'function') {
      this.getter = expOrFn;
    } else {
      // TODO
    }
  }

  public get(key: string) {
    Dep.target = this;
    //this.value = data[key]
    //Dep.target = null;
  }
}
