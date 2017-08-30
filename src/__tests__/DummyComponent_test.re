open Jest;

let setup ::title="Test" ::handleClick=(fun _evt => ()) () =>
  Enzyme.shallow <DummyComponent title handleClick />;

let header wrapper =>
  wrapper
  |> Enzyme.find "#header"
  |> Enzyme.first;

let listItems wrapper =>
  wrapper
  |> Enzyme.find "#list"
  |> Enzyme.children;

describe "DummyComponent" (fun () => {
  open Expect;

  test "renders a #header" (fun () => {
    let title = "A test title";
    let wrapper = setup title::title ();
    let headerNodes = wrapper |> header;

    expect (Enzyme.length headerNodes) |> toBe 1;
  });

  test "has the expected title in the #header" (fun () => {
    let title = "A test title";
    let wrapper = setup title::title ();
    let headerText = wrapper |> header |> Enzyme.text;

    expect headerText |> toContainString title;
  });

  test "has the expected h1 tag in the #header" (fun () => {
    let title = "A test title";
    let wrapper = setup title::title ();
    let expectedNode = <h1>(ReasonReact.stringToElement title)</h1>;

    expect (Enzyme.contains expectedNode wrapper) |> toBe true;
  });

  test "has the expected #header" (fun () => {
    let title = "A test title";
    let header = setup title::title () |> header;
    let expectedNode = <div id="header">
      <h1>(ReasonReact.stringToElement title)</h1>
    </div>;

    expect (Enzyme.equals expectedNode header) |> toBe true;
  });

  test "initially has its `clicked` state set to false" (fun () => {
    let wrapper = setup ();
    let { clicked }: DummyComponent.state = Enzyme.state wrapper;
    expect clicked |> toBe false;
  });

  test "folds left properly" (fun () => {
    let items = setup () |> listItems;
    let result =  Enzyme.foldLeft (fun text node => text ^ Enzyme.text node) "" items;
    expect result |> toBe "OneTwoThree";
  });

  test "folds right properly" (fun () => {
    let items = setup () |> listItems;
    let result =  Enzyme.foldRight (fun text node => text ^ Enzyme.text node) "" items;
    expect result |> toBe "ThreeTwoOne";
  });
});
