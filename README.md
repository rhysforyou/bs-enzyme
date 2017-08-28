# bs-enzyme - [BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [Enzyme](https://github.com/airbnb/enzyme)

:construction: **Note:** This package is still _very_ experimental :construction:

---

## Status

- Most of the `shallow` API is implemented
- The `simulate` method is currently wrapped in multiple `simulateN` functions to handle mixed variadic arguments
- Neither the `render` nor `mount` APIs are implemented
- I haven't extensively tested most of the functions, so some might be broken

## Example

Using the excellent [bs-jest](https://github.com/reasonml-community/bs-jest)

```reason
open Jest;

let setup ::activeFilter=(Filter.All) ::onChange=(fun _filter => ()) () =>
  Enzyme.shallow <FilterBar activeFilter onChange />;

let filters wrapper =>
  wrapper
  |> Enzyme.find ".filters"
  |> Enzyme.children;

let activeFilters wrapper =>
  wrapper
  |> filters
  |> Enzyme.find ".active";

let inactiveFilters wrapper =>
  wrapper
  |> filters
  |> Enzyme.find ".inactive";

describe "FilterBar" (fun () => {
  open Expect;

  describe "when the active filter is 'All'" (fun () => {
    let wrapper = setup activeFilter::Filter.All ();

    test "renders All with the .active class" (fun () => {
      let activeFilterText = wrapper |> activeFilters |> Enzyme.text;
      expect activeFilterText |> toContainString "All";
    });

    test "only renders one active filter" (fun () => {
      let activeFilterCount = wrapper |> activeFilters |> Enzyme.getLength;
      expect activeFilterCount |> toBe 1;
    });

    test "renders the other two filters with the .inactive class" (fun () => {
      let inactiveCount = wrapper |> inactiveFilters |> Enzyme.getLength;
      expect inactiveCount |> toBe 2;
    });
  });
});
```

## Installation

```
$ npm install --save-dev bs-enzyme
```

Then add `bs-enzyme` to `bs-dev-dependencies` in your `bsconfig.json`:

```json
{
  ...
  "bs-dev-dependencies": ["bs-enzyme"]
}
```

**Note:** If you're using this package with `bs-jest`, be sure to list `bs-enzyme` first in your dependencies.
