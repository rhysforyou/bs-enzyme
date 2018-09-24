type node = ReasonReact.reactElement;

type selector = string;

module Impl = {
  type t;

  type predicate = t => bool;

  [@bs.send.pipe: t] external find: selector => t = "find";

  [@bs.send.pipe: t] external findWhere: predicate => t = "findWhere";

  [@bs.send.pipe: t] external filter: selector => t = "filter";

  [@bs.send.pipe: t] external filterWhere: predicate => t = "filterWhere";

  [@bs.send.pipe: t] external contains: node => bool = "contains";

  [@bs.send.pipe: t] external containsAll: array(node) => bool = "contains";

  [@bs.send.pipe: t] external containsMatchingElement: node => bool = "containsMatchingElement";

  [@bs.send.pipe: t] external containsAllMatchingElements: array(node) => bool = "containsAllMatchingElements";

  [@bs.send.pipe: t] external containsAnyMatchingElements: array(node) => bool = "containsAnyMatchingElements";

  [@bs.send.pipe: t] external equals: node => bool = "equals";

  [@bs.send.pipe: t] external matchesElement: node => bool = "matchesElement";

  [@bs.send.pipe: t] external hasClass: string => bool = "hasClass";

  [@bs.send.pipe: t] external is: selector => bool = "is";

  [@bs.send] external exists: t => bool = "exists";

  [@bs.send] external isEmptyRender: t => bool = "isEmptyRender";

  [@bs.send.pipe: t] external not: selector => t = "not";

  [@bs.send] external children: t => t = "children";

  [@bs.send.pipe: t] external childAt: int => t = "childAt";

  [@bs.send] external parents: t => t = "parents";

  [@bs.send] external parent: t => t = "parent";

  [@bs.send.pipe: t] external closest: selector => t = "closest";

  [@bs.send] external unmount: t => t = "unmount";

  [@bs.send] external text: t => string = "text";

  [@bs.send] external html: t => string = "html";

  [@bs.send.pipe: t] external get: int => node = "get";

  [@bs.send] external getNode: t => node = "getNode";

  [@bs.send] external getNodes: t => array(node) = "getNodes";

  [@bs.send.pipe: t] external at: int => t = "at";

  [@bs.send] external first: t => t = "first";

  [@bs.send] external last: t => t = "last";

  /* TODO: Find a better way to do this */
  [@bs.send.pipe: t] external simulate: string => unit = "simulate";

  [@bs.send.pipe: t] external simulate1: (string, 'a) => unit = "simulate";

  [@bs.send.pipe: t] external simulate2: (string, 'a, 'b) => unit = "simulate";

  [@bs.send.pipe: t] external simulate3: (string, 'a, 'b, 'c) => unit = "simulate";

  [@bs.send.pipe: t] external simulate4: (string, 'a, 'b, 'c, 'd) => unit = "simulate";

  [@bs.splice] [@bs.send.pipe: t] external simulateMany: (string, ~args: array('a)) => unit = "simulate";

  [@bs.send] external jsState: t => Js.t({..}) = "state";

  [@bs.send.pipe: t] external jsStateFor: string => Js.t({..}) = "state";

  [@bs.send.pipe: t] external setJsState: Js.t({..}) => unit = "setState";

  [@bs.send] external jsContext: t => Js.t({..}) = "context";

  [@bs.send.pipe: t] external jsContextFor: string => Js.t({..}) = "context";

  [@bs.send.pipe: t] external setJsContext: Js.t({..}) => unit = "setContext";

  [@bs.send] external jsProps: t => Js.t({..}) = "props";

  [@bs.send.pipe: t] external jsPropFor: string => Js.t({..}) = "prop";

  [@bs.send.pipe: t] external setJsProps: Js.t({..}) => unit = "setProps";

  [@bs.send] external key: t => string = "key";

  let state = t: 'state => jsState(t)##reasonState;

  [@bs.send] external instance: t => node = "instance";

  [@bs.send] external update: t => unit = "update";

  [@bs.send] external debug: t => string = "debug";

  [@bs.send] external type_: t => string = "type";

  [@bs.send] external name: t => string = "name";

  [@bs.send.pipe: t] external forEach: (t => unit) => t = "forEach";

  [@bs.send.pipe: t] external map: (t => 'a) => array('a) = "forEach";

  [@bs.send.pipe: t] external foldLeft: (('a, t) => 'a, 'a) => 'a = "reduce";

  [@bs.send.pipe: t] external foldRight: (('a, t) => 'a, 'a) => 'a = "reduceRight";

  [@bs.get] external length: t => int = "length";
};

module Shallow = {
  include Impl;
};

[@bs.module "enzyme"] external shallow: node => Shallow.t = "";

type adapter;

type js_obj_with_adapter = {. "adapter": adapter};

[@bs.module "enzyme"] external configure: js_obj_with_adapter => adapter = "configure";

[@bs.module] [@bs.new] external react_16_adapter: unit => adapter = "enzyme-adapter-react-16";

[@bs.module] [@bs.new] external react_15_adapter: unit => adapter = "enzyme-adapter-react-15";

[@bs.module] [@bs.new] external react_15_4_adapter: unit => adapter = "enzyme-adapter-react-15.4";

[@bs.module] [@bs.new] external react_14_adapter: unit => adapter = "enzyme-adapter-react-14";

[@bs.module] [@bs.new] external react_13_adapter: unit => adapter = "enzyme-adapter-react-13";

[@bs.module] [@bs.new] external preact_adapter: unit => adapter = "preact-enzyme-adapter";

[@bs.module] [@bs.new] external inferno_adapter: unit => adapter = "enzyme-adapter-inferno";

let configureEnzyme = (adapter: adapter) => configure({"adapter": adapter});
