function observe(val: any) {
  if (!isObject(val)) {
    return null;
  }

  return new Observer(val);
}

class Observer {
  private data: IData;

  constructor(data: IData) {
    this.data = data;
  }

  public walk(data: IData) {
    Object.keys(data).forEach(key => this.convert(key, data[key]));
  }

  private convert<T>(key: string, val: T) {
    this.defineReactive(this.data, key, val);
  }

  private defineReactive<T>(data: IData, key: string, val: T) {
    const dep = new Dep();
    let childObj = observe(val);

    Object.defineProperty(data, key, {
      enumerable: true,
      configurable: false,
      get() {
        if (Dep.target != null) {
          dep.depend();
        }

        return val;
      },
      set(newVal) {
        if (newVal === val) {
          return;
        }
        val = newVal;
        // 新值监听
        childObj = observe(newVal);
        // 通知回调
        dep.notify();
      }
    })
  }
}
