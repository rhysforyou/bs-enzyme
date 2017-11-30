type state = {clicked: bool};

let se = ReasonReact.stringToElement;

let component = ReasonReact.statefulComponent("DummyComponent");

let make = (~title, ~handleClick, _children) => {
  ...component,
  initialState: () => {clicked: false},
  render: ({state}) =>
    <div className="dummy">
      <div id="header"> <h1> (se(title)) </h1> </div>
      <div id="content">
        <button id="click-me" onClick=handleClick>
          (se(state.clicked ? "I've been clicked!" : "Click Me!"))
        </button>
        <ul id="list"> <li> (se("One")) </li> <li> (se("Two")) </li> <li> (se("Three")) </li> </ul>
      </div>
    </div>
};
