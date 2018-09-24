type state = {clicked: bool};

type action = 
  | Click;

let se = ReasonReact.string;

let component = ReasonReact.reducerComponent("DummyComponent");

let make = (~title, _children) => {
  ...component,
  initialState: () => {clicked: false},
  reducer: (action, state) => 
    switch(action) {
    | Click => ReasonReact.Update({clicked: ! state.clicked})
    },
  render: self =>
    <div className="dummy">
      <div id="header"> <h1> (se(title)) </h1> </div>
      <div id="content">
        <button id="click-me" onClick=(_event => self.send(Click))>
          (se(self.state.clicked ? "I've been clicked!" : "Click Me!"))
        </button>
        <ul id="list"> <li> (se("One")) </li> <li> (se("Two")) </li> <li> (se("Three")) </li> </ul>
      </div>
    </div>
};
