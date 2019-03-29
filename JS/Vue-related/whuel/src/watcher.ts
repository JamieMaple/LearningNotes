class Watcher {
  constructor() {
    // TODO
  }

  public get(key: string) {
    Dep.target = this;
    //this.value = data[key]
    //Dep.target = null;
  }
}
