type state = {
  clicked: bool
};
let se = ReasonReact.stringToElement;
let component = ReasonReact.statefulComponent "DummyComponent";

let make title::title handleClick::handleClick _children => {
  ...component,
  initialState: fun () => {
    clicked: false
  },
  render: fun {state} => {
    <div className="dummy">
      <div id="header">
        <h1>(se title)</h1>
      </div>
      <div id="content">
        <button id="click-me" onClick=handleClick>
          (se (state.clicked ? "I've been clicked!" : "Click Me!"))
        </button>
      </div>
    </div>
  }
}
