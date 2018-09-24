open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("Shallow rendering", () => {
  let setup = (~title="Test", ()) =>
    Enzyme.shallow(<DummyComponent title />);

  let header = (wrapper) =>
    wrapper
    |> Enzyme.Shallow.find("#header")
    |> Enzyme.Shallow.first;

  let listItems = (wrapper) =>
    wrapper
    |> Enzyme.Shallow.find("#list")
    |> Enzyme.Shallow.children;

  describe("DummyComponent", () => {
    open Expect;

    test("renders a #header", () => {
      let title = "A test title";
      let wrapper = setup(~title, ());
      let headerNodes = wrapper |> header;
      expect(Enzyme.Shallow.length(headerNodes)) |> toBe(1)
    });

    test("has the expected title in the #header", () => {
      let title = "A test title";
      let wrapper = setup(~title, ());
      let headerText = wrapper |> header |> Enzyme.Shallow.text;
      expect(headerText) |> toContainString(title)
    });

    test("has the expected h1 tag in the #header", () => {
      let title = "A test title";
      let wrapper = setup(~title, ());
      let expectedNode = <h1> (ReasonReact.string(title)) </h1>;
      expect(Enzyme.Shallow.contains(expectedNode, wrapper)) |> toBe(true)
    });

    test("has the expected #header", () => {
      let title = "A test title";
      let header = setup(~title, ()) |> header;
      let expectedNode =
        <div id="header"> <h1> (ReasonReact.string(title)) </h1> </div>;
      expect(Enzyme.Shallow.equals(expectedNode, header)) |> toBe(true)
    });

    test("initially has its `clicked` state set to false", () => {
      let wrapper = setup();
      let {clicked}: DummyComponent.state = Enzyme.Shallow.state(wrapper);
      expect(clicked) |> toBe(false)
    });

    test("folds left properly", () => {
      let items = setup() |> listItems;
      let result = Enzyme.Shallow.foldLeft((text, node) => text ++ Enzyme.Shallow.text(node), "", items);
      expect(result) |> toBe("OneTwoThree")
    });

    test("folds right properly", () => {
      let items = setup() |> listItems;
      let result = Enzyme.Shallow.foldRight((text, node) => text ++ Enzyme.Shallow.text(node), "", items);
      expect(result) |> toBe("ThreeTwoOne")
    });
  });
});

describe("Full DOM rendering", () => {
  let setup = (~title="Test", ()) =>
  Enzyme.mount(<DummyComponent title />);

  let header = (wrapper) =>
    wrapper
    |> Enzyme.Mount.find("#header")
    |> Enzyme.Mount.first;

  let listItems = (wrapper) =>
    wrapper
    |> Enzyme.Mount.find("#list")
    |> Enzyme.Mount.children;

  describe("DummyComponent", () => {
    open Expect;

    test("renders a #header", () => {
      let title = "A test title";
      let wrapper = setup(~title, ());
      let headerNodes = wrapper |> header;
      expect(Enzyme.Mount.length(headerNodes)) |> toBe(1)
    });

    test("has the expected title in the #header", () => {
      let title = "A test title";
      let wrapper = setup(~title, ());
      let headerText = wrapper |> header |> Enzyme.Mount.text;
      expect(headerText) |> toContainString(title)
    });

    test("has the expected h1 tag in the #header", () => {
      let title = "A test title";
      let wrapper = setup(~title, ());
      let expectedNode = <h1> (ReasonReact.string(title)) </h1>;
      expect(Enzyme.Mount.contains(expectedNode, wrapper)) |> toBe(true)
    });

    test("initially has its `clicked` state set to false", () => {
      let wrapper = setup();
      let {clicked}: DummyComponent.state = Enzyme.Mount.state(wrapper);
      expect(clicked) |> toBe(false)
    });

    test("folds left properly", () => {
      let items = setup() |> listItems;
      let result = Enzyme.Mount.foldLeft((text, node) => text ++ Enzyme.Mount.text(node), "", items);
      expect(result) |> toBe("OneTwoThree")
    });

    test("folds right properly", () => {
      let items = setup() |> listItems;
      let result = Enzyme.Mount.foldRight((text, node) => text ++ Enzyme.Mount.text(node), "", items);
      expect(result) |> toBe("ThreeTwoOne")
    });
  });
});
