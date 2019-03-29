let uuid: number = 0;


class Dep {
  private id: number = uuid++;
  private subs: Array<ISub> = [];

  public static target: object = null;
  
  public addSub(sub: ISub) {
    this.subs.push(sub);
  }

  public depend() {
    /* TODO */
    throw 'unfinished depend method'
  }

  public removeSub(sub: ISub) {
    const index = this.subs.indexOf(sub);
    if (index > -1) {
      this.subs.splice(index);
    }
  }

  public notify() {
    this.subs.forEach(sub => sub.update());
  }
}
