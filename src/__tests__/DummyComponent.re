type state = {clicked: bool};

type action =
  | Click;

let se = React.string;

[@react.component]
let make = (~title) => {
  let (state, dispatch) = React.useReducer(
    (state, action) =>
    switch action {
    | Click => {clicked: !state.clicked}
    },
    {clicked: false}
  );
  
  <div className="dummy">
    <div id="header"> <h1> (se(title)) </h1> </div>
    <div id="content">
      <button id="click-me" onClick=((_event) => dispatch(Click))>
        (se(state.clicked ? "I've been clicked!" : "Click Me!"))
      </button>
      <ul id="list"> <li> (se("One")) </li> <li> (se("Two")) </li> <li> (se("Three")) </li> </ul>
    </div>
  </div>
};