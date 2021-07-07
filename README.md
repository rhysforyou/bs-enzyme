# bs-enzyme

[![Travis](https://img.shields.io/travis/rhysforyou/bs-enzyme.svg?style=flat-square)](https://travis-ci.org/rhysforyou/bs-enzyme) [![npm (scoped)](https://img.shields.io/npm/v/bs-enzyme.svg?style=flat-square)](https://www.npmjs.com/package/bs-enzyme)

[BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [Enzyme](https://github.com/airbnb/enzyme)

⚠️ **Note:** This package is deprecated. It's recommended that you instead use [Reason Testing Library](https://testing-library.com/docs/bs-react-testing-library/intro/). ⚠️

---

## Status

- Most of the `shallow` and `mount` APIs are implemented
- The `simulate` method is currently wrapped in multiple `simulateN` functions
  to handle mixed variadic arguments
- The `render` API isn't implemented
- I haven't extensively tested most of the functions, so some might be broken

## Example

Using the excellent [bs-jest](https://github.com/reasonml-community/bs-jest) and Airbnb's official [enzyme-adapter-react-16](https://github.com/airbnb/enzyme).

```reason
open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~title="Test", ~handleClick=(_evt) => (), ()) =>
  Enzyme.shallow(<DummyComponent title handleClick />);

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

  test("has the expected h1 tag in the #header", () => {
    let title = "A test title";
    let wrapper = setup(~title, ());
    let expectedNode = <h1> (ReasonReact.stringToElement(title)) </h1>;
    expect(Enzyme.Shallow.contains(expectedNode, wrapper)) |> toBe(true)
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

  test("maps properly", () => {
    let items = setup() |> listItems;
    let result = Enzyme.Shallow.map(node => Enzyme.Shallow.text(node), items);
    expect(result) |> toEqual([|"One", "Two", "Three"|])
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
yarn add --dev bs-enzyme enzyme-adapter-react-16
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
