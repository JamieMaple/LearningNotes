function createElement(tag, attrs, ...children) {
  return {
    tag,
    attrs,
    children
  }
}

class Component {
  constructor(props) {
    this.state = {}
    this.props = props
  }

  setState(stateChange) {
    Object.assign(this.state, stateChange)
    renderComponent(this)
  }
}

// 根据组件对象渲染到真正的 dom，同时包括触发生命周期
function renderComponent(component) {
  let base
  const renderer = component.render()
  
  if (component.base && component.componentWillUpdate) {
    component.componentWillUpdate()
  }

  base = _render(renderer)
  
  if (component.base) {
    if (component.componentDidUpdate) {
      component.componentDidUpdate()
    }
  } else if (component.componentDidMount) {
    component.componentDidMount()
  }

  if (component.base && component.base.parentNode) {
    component.base.parentNode.replaceChild(base, component.base)
  }

  component.base = base
  base._component = component
}

function isPrimitive(v) {
  return typeof v === 'string' || typeof v === 'number'
    || typeof v === 'undefined' || typeof v === 'null'
    || typeof v === 'boolean' || typeof v === 'symbol'
}

function isFunction(v) {
  return typeof v === 'function'
}

function _render(vnode) {
  if (isPrimitive(vnode)) {
    const textNode = document.createTextNode(String(vnode))
    return textNode
  }

  if (isFunction(vnode.tag)) {
    const component = createComponent(vnode.tag, vnode.attrs)
    setComponentProps(component, vnode.attrs)
    return component.base
  }

  const dom = document.createElement(vnode.tag)

  if (vnode.attrs) {
    Object.keys(vnode.attrs).forEach(key => {
      const value = vnode.attrs[key]
      setAttribute(dom, key, value)
    })
  }

  Array.isArray(vnode.children) && vnode.children.forEach(child => render(child, dom))

  return dom
}

function setAttribute(dom, name, value) {
  if (name === 'className') {
    name = 'class'
  }

  // 事件监听
  if (/on\w+/.test(name)) {
    name = name.toLowerCase()
    dom[name] = value || ''
  } else if (name === 'style') {
    if (!value || typeof value === 'string') {
      dom.style.cssText = value || ''
    } else if (value && typeof value === 'object') {
      for (let styleName in value) {
        dom.style[styleName] = typeof value[styleName] === 'number' ? value[styleName] + 'px' : value[styleName]
      }
    }
  } else {
    if (name in dom) {
      dom[name] = value || ''
    }
    if (value) {
      dom.setAttribute(name, value)
    } else {
      dom.removeAttribute(name)
    }
  }
}

// 创建组建对象
function createComponent(component, props) {
  let inst
  if (component.prototype && component.prototype.render) {
    // class component
    inst = new component(props)
  } else {
    // functional component
    inst = new Component()
    inst.constructor = component
    inst.render = function() {
      return this.constructor(props)
    }
  }

  return inst
}

// 触发组件更新生命周期
function setComponentProps(component, props) {
  if (!component.base) {
    if (component.componentWillMount) {
      component.componentWillMount()
    }
  } else if (component.componentWillReceiveProps) {
    component.componentWillReceiveProps(props)
  }

  component.props = props
  renderComponent(component)
}

const React = {
  createElement,
  Component
}

export default React
export function render(vnode, container) {
  const renderer = _render(vnode)
  container.appendChild(renderer)
}

