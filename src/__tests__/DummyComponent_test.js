// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Jest from "@glennsl/bs-jest/src/jest.js";
import * as React from "react";
import * as Enzyme from "../Enzyme.js";
import * as Enzyme$1 from "enzyme";
import * as DummyComponent from "./DummyComponent.js";
import * as EnzymeAdapterReact from "enzyme-adapter-react-16";

Enzyme.configureEnzyme(new EnzymeAdapterReact.default());

Jest.describe("Shallow rendering", (function (param) {
        var setup = function (titleOpt, param) {
          var title = titleOpt !== undefined ? titleOpt : "Test";
          return Enzyme$1.shallow(React.createElement(DummyComponent.make, {
                          title: title
                        }));
        };
        return Jest.describe("DummyComponent", (function (param) {
                      Jest.test("renders a #header", (function (param) {
                              var wrapper = setup("A test title", undefined);
                              var headerNodes = wrapper.find("#header").first();
                              return Jest.Expect.toBe(1, Jest.Expect.expect(headerNodes.length));
                            }));
                      Jest.test("has the expected title in the #header", (function (param) {
                              var title = "A test title";
                              var wrapper = setup(title, undefined);
                              var headerText = wrapper.find("#header").first().text();
                              return Jest.Expect.toContainString(title, Jest.Expect.expect(headerText));
                            }));
                      Jest.test("has the expected h1 tag in the #header", (function (param) {
                              var title = "A test title";
                              var wrapper = setup(title, undefined);
                              var expectedNode = React.createElement("h1", undefined, title);
                              return Jest.Expect.toBe(true, Jest.Expect.expect(wrapper.contains(expectedNode)));
                            }));
                      Jest.test("has the expected #header", (function (param) {
                              var title = "A test title";
                              var wrapper = setup(title, undefined);
                              var header = wrapper.find("#header").first();
                              var expectedNode = React.createElement("div", {
                                    id: "header"
                                  }, React.createElement("h1", undefined, title));
                              return Jest.Expect.toBe(true, Jest.Expect.expect(header.equals(expectedNode)));
                            }));
                      Jest.test("initially has its `clicked` state set to false", (function (param) {
                              var wrapper = setup(undefined, undefined);
                              var button = wrapper.find("#click-me");
                              var buttonText = button.text();
                              return Jest.Expect.toEqual("Click Me!", Jest.Expect.expect(buttonText));
                            }));
                      Jest.test("folds left properly", (function (param) {
                              var wrapper = setup(undefined, undefined);
                              var items = wrapper.find("#list").children();
                              var result = items.reduce((function (text, node) {
                                      return text + node.text();
                                    }), "");
                              return Jest.Expect.toBe("OneTwoThree", Jest.Expect.expect(result));
                            }));
                      Jest.test("folds right properly", (function (param) {
                              var wrapper = setup(undefined, undefined);
                              var items = wrapper.find("#list").children();
                              var result = items.reduceRight((function (text, node) {
                                      return text + node.text();
                                    }), "");
                              return Jest.Expect.toBe("ThreeTwoOne", Jest.Expect.expect(result));
                            }));
                      return Jest.test("maps properly", (function (param) {
                                    var wrapper = setup(undefined, undefined);
                                    var items = wrapper.find("#list").children();
                                    var result = items.map(function (node) {
                                          return node.text();
                                        });
                                    return Jest.Expect.toEqual([
                                                "One",
                                                "Two",
                                                "Three"
                                              ], Jest.Expect.expect(result));
                                  }));
                    }));
      }));

Jest.describe("Full DOM rendering", (function (param) {
        var setup = function (titleOpt, param) {
          var title = titleOpt !== undefined ? titleOpt : "Test";
          return Enzyme$1.mount(React.createElement(DummyComponent.make, {
                          title: title
                        }));
        };
        return Jest.describe("DummyComponent", (function (param) {
                      Jest.test("renders a #header", (function (param) {
                              var wrapper = setup("A test title", undefined);
                              var headerNodes = wrapper.find("#header").first();
                              return Jest.Expect.toBe(1, Jest.Expect.expect(headerNodes.length));
                            }));
                      Jest.test("has the expected title in the #header", (function (param) {
                              var title = "A test title";
                              var wrapper = setup(title, undefined);
                              var headerText = wrapper.find("#header").first().text();
                              return Jest.Expect.toContainString(title, Jest.Expect.expect(headerText));
                            }));
                      Jest.test("has the expected h1 tag in the #header", (function (param) {
                              var title = "A test title";
                              var wrapper = setup(title, undefined);
                              var expectedNode = React.createElement("h1", undefined, title);
                              return Jest.Expect.toBe(true, Jest.Expect.expect(wrapper.contains(expectedNode)));
                            }));
                      Jest.test("initially has its `clicked` state set to false", (function (param) {
                              var wrapper = setup(undefined, undefined);
                              var button = wrapper.find("#click-me");
                              var buttonText = button.text();
                              return Jest.Expect.toEqual("Click Me!", Jest.Expect.expect(buttonText));
                            }));
                      Jest.test("folds left properly", (function (param) {
                              var wrapper = setup(undefined, undefined);
                              var items = wrapper.find("#list").children();
                              var result = items.reduce((function (text, node) {
                                      return text + node.text();
                                    }), "");
                              return Jest.Expect.toBe("OneTwoThree", Jest.Expect.expect(result));
                            }));
                      return Jest.test("folds right properly", (function (param) {
                                    var wrapper = setup(undefined, undefined);
                                    var items = wrapper.find("#list").children();
                                    var result = items.reduceRight((function (text, node) {
                                            return text + node.text();
                                          }), "");
                                    return Jest.Expect.toBe("ThreeTwoOne", Jest.Expect.expect(result));
                                  }));
                    }));
      }));

export {
  
}
/*  Not a pure module */
