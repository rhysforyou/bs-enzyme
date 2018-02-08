# bs-enzyme - [BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [Enzyme](https://github.com/airbnb/enzyme) [![npm (scoped)](https://img.shields.io/npm/v/bs-enzyme.svg?style=flat-square)](https://www.npmjs.com/package/bs-enzyme)

:construction: **Note:** This package is still _very_ experimental. Expect
frequent, breaking changes right up until 1.0 is released. :construction:

---

## Status

* Most of the `shallow` API is implemented
* The `simulate` method is currently wrapped in multiple `simulateN` functions
  to handle mixed variadic arguments
* Neither the `render` nor `mount` APIs are implemented
* I haven't extensively tested most of the functions, so some might be broken

## Example

Using the excellent [bs-jest](https://github.com/reasonml-community/bs-jest) and Airbnb's official [enzyme-adapter-react-16](https://github.com/airbnb/enzyme).

```reason
open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~title="Test", ~handleClick=(_evt) => (), ()) =>
  Enzyme.shallow(<DummyComponent title handleClick />);

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

  test("has the expected h1 tag in the #header", () => {
    let title = "A test title";
    let wrapper = setup(~title, ());
    let expectedNode = <h1> (ReasonReact.stringToElement(title)) </h1>;
    expect(Enzyme.contains(expectedNode, wrapper)) |> toBe(true)
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
});
```

See more examples in the project's
[tests directory](https://github.com/rpowelll/bs-enzyme/tree/master/src/__tests__).

## Installation

With npm:

```sh
npm install --save-dev bs-enzyme enzyme-adapter-react-16
```

With Yarn:

```sh
yarn add bs-enzyme enzyme-adapter-react-16
```

Then add `bs-enzyme` to `bs-dev-dependencies` in your `bsconfig.json`:

```json
{
  ...
  "bs-dev-dependencies": ["bs-enzyme"]
}
```

**Note:** If you're using this package with `bs-jest`, be sure to list
`bs-enzyme` first in your dependencies.
