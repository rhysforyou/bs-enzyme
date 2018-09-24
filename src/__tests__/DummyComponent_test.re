open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~title="Test", ()) =>
  Enzyme.shallow(<DummyComponent title />);

let header = (wrapper) =>
wrapper
  |> Enzyme.find("#header")
  |> Enzyme.first;

let listItems = (wrapper) =>
  wrapper
  |> Enzyme.find("#list")
  |> Enzyme.children;

describe("DummyComponent", () => {
  open Expect;

  test("renders a #header", () => {
    let title = "A test title";
    let wrapper = setup(~title, ());
    let headerNodes = wrapper |> header;
    expect(Enzyme.length(headerNodes)) |> toBe(1)
  });

  test("has the expected title in the #header", () => {
    let title = "A test title";
    let wrapper = setup(~title, ());
    let headerText = wrapper |> header |> Enzyme.text;
    expect(headerText) |> toContainString(title)
  });

  test("has the expected h1 tag in the #header", () => {
    let title = "A test title";
    let wrapper = setup(~title, ());
    let expectedNode = <h1> (ReasonReact.string(title)) </h1>;
    expect(Enzyme.contains(expectedNode, wrapper)) |> toBe(true)
  });

  test("has the expected #header", () => {
    let title = "A test title";
    let header = setup(~title, ()) |> header;
    let expectedNode =
      <div id="header"> <h1> (ReasonReact.string(title)) </h1> </div>;
    expect(Enzyme.equals(expectedNode, header)) |> toBe(true)
  });

  test("initially has its `clicked` state set to false", () => {
    let wrapper = setup();
    let {clicked}: DummyComponent.state = Enzyme.state(wrapper);
    expect(clicked) |> toBe(false)
  });

  test("folds left properly", () => {
    let items = setup() |> listItems;
    let result = Enzyme.foldLeft((text, node) => text ++ Enzyme.text(node), "", items);
    expect(result) |> toBe("OneTwoThree")
  });

  test("folds right properly", () => {
    let items = setup() |> listItems;
    let result = Enzyme.foldRight((text, node) => text ++ Enzyme.text(node), "", items);
    expect(result) |> toBe("ThreeTwoOne")
  });
});
