class Compile {
  public $vm: object;
  public $el: Element;
  public $fragment: DocumentFragment;

  constructor(el: Element | string, vm: object) {
    if (typeof el === 'string') {
      this.$el = document.querySelector(el);
    } else if (isElementNode(el)) {
      this.$el = el;
    } else {
      throw new TypeError('el must be Element Node or string selector');
    }

    if (this.$el) {
      this.$fragment = this.node2Fragment(this.$el);
      this.init();
      this.$el.appendChild(this.$fragment);
    }
  }

  private node2Fragment(el: Element) {
    const fragment = document.createDocumentFragment();
    let child = el.firstChild;

    while (child != null) {
      fragment.appendChild(child)
      child = el.firstChild;
    }

    return fragment;
  }

  private init() {
    
  }

  private compileElement(el: Node) {
    const childNodes = el.childNodes;
    Array.from(childNodes).forEach(node => {
      const text = node.textContent;
      const reg = /\{\{(.*)\}\}/;

      if (isElementNode(node)) {
        this.compile(<Element>node);
      } else if (isTextNode(node) && reg.test(text)) {
        
      }

      if (node.childNodes && node.childNodes.length) {
        this.compileElement(node);
      }
    })
  }

  private compile(node: Element) {
    const nodeAttributes = node.attributes;

    Array.from(nodeAttributes).forEach(attr => {
      const attrName = attr.name;

      if (Directive.isDirective(attrName)) {
        const exp = attr.value;
        const dir = attrName.substring(2);

        // TODO
        if (Directive.isEventDirective(dir)) {
          // event
        } else {
          // normal
        }
        node.removeAttribute(attrName);
      }
    })
  }
}

class Directive {
  public static isDirective(attr: string) {
    return attr.startsWith('v-');
  }

  public static isEventDirective(dir: string) {
    return dir.startsWith('on');
  }
}
