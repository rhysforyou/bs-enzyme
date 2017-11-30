type shallowWrapper;

type node = ReasonReact.reactElement;

type selector = string;

type predicate = shallowWrapper => bool;

[@bs.module "enzyme"] external shallow : node => shallowWrapper = "";

[@bs.send.pipe : shallowWrapper] external find : selector => shallowWrapper = "find";

[@bs.send.pipe : shallowWrapper] external findWhere : predicate => shallowWrapper = "findWhere";

[@bs.send.pipe : shallowWrapper] external filter : selector => shallowWrapper = "filter";

[@bs.send.pipe : shallowWrapper]
external filterWhere : predicate => shallowWrapper = "filterWhere";

[@bs.send.pipe : shallowWrapper] external contains : node => bool = "contains";

[@bs.send.pipe : shallowWrapper] external containsAll : array(node) => bool = "contains";

[@bs.send.pipe : shallowWrapper]
external containsMatchingElement : node => bool = "containsMatchingElement";

[@bs.send.pipe : shallowWrapper]
external containsAllMatchingElements : array(node) => bool = "containsAllMatchingElements";

[@bs.send.pipe : shallowWrapper]
external containsAnyMatchingElements : array(node) => bool = "containsAnyMatchingElements";

[@bs.send.pipe : shallowWrapper] external equals : node => bool = "equals";

[@bs.send.pipe : shallowWrapper] external matchesElement : node => bool = "matchesElement";

[@bs.send.pipe : shallowWrapper] external hasClass : string => bool = "hasClass";

[@bs.send.pipe : shallowWrapper] external is : selector => bool = "is";

[@bs.send] external exists : shallowWrapper => bool = "exists";

[@bs.send] external isEmptyRender : shallowWrapper => bool = "isEmptyRender";

[@bs.send.pipe : shallowWrapper] external not : selector => shallowWrapper = "not";

[@bs.send] external children : shallowWrapper => shallowWrapper = "children";

[@bs.send.pipe : shallowWrapper] external childAt : int => shallowWrapper = "childAt";

[@bs.send] external parents : shallowWrapper => shallowWrapper = "parents";

[@bs.send] external parent : shallowWrapper => shallowWrapper = "parent";

[@bs.send.pipe : shallowWrapper] external closest : selector => shallowWrapper = "closest";

[@bs.send] external unmount : shallowWrapper => shallowWrapper = "unmount";

[@bs.send] external text : shallowWrapper => string = "text";

[@bs.send] external html : shallowWrapper => string = "html";

[@bs.send.pipe : shallowWrapper] external get : int => node = "get";

[@bs.send] external getNode : shallowWrapper => node = "getNode";

[@bs.send] external getNodes : shallowWrapper => array(node) = "getNodes";

[@bs.send.pipe : shallowWrapper] external at : int => shallowWrapper = "at";

[@bs.send] external first : shallowWrapper => shallowWrapper = "first";

[@bs.send] external last : shallowWrapper => shallowWrapper = "last";

/* TODO: Find a better way to do this */
[@bs.send.pipe : shallowWrapper] external simulate : string => unit = "simulate";

[@bs.send.pipe : shallowWrapper] external simulate1 : (string, 'a) => unit = "simulate";

[@bs.send.pipe : shallowWrapper] external simulate2 : (string, 'a, 'b) => unit = "simulate";

[@bs.send.pipe : shallowWrapper] external simulate3 : (string, 'a, 'b, 'c) => unit = "simulate";

[@bs.send.pipe : shallowWrapper]
external simulate4 : (string, 'a, 'b, 'c, 'd) => unit = "simulate";

[@bs.splice] [@bs.send.pipe : shallowWrapper]
external simulateMany : (string, ~args: array('a)) => unit = "simulate";

[@bs.send] external jsState : shallowWrapper => Js.t({..}) = "state";

[@bs.send.pipe : shallowWrapper] external jsStateFor : string => Js.t({..}) = "state";

[@bs.send.pipe : shallowWrapper] external setJsState : Js.t({..}) => unit = "setState";

[@bs.send] external jsContext : shallowWrapper => Js.t({..}) = "context";

[@bs.send.pipe : shallowWrapper] external jsContextFor : string => Js.t({..}) = "context";

[@bs.send.pipe : shallowWrapper] external setJsContext : Js.t({..}) => unit = "setContext";

[@bs.send] external jsProps : shallowWrapper => Js.t({..}) = "props";

[@bs.send.pipe : shallowWrapper] external jsPropFor : string => Js.t({..}) = "prop";

[@bs.send.pipe : shallowWrapper] external setJsProps : Js.t({..}) => unit = "setProps";

[@bs.send] external key : shallowWrapper => string = "key";

let state = (shallowWrapper) : 'state => jsState(shallowWrapper)##reasonState;

[@bs.send] external instance : shallowWrapper => node = "instance";

[@bs.send] external update : shallowWrapper => unit = "update";

[@bs.send] external debug : shallowWrapper => string = "debug";

[@bs.send] external type_ : shallowWrapper => string = "type";

[@bs.send] external name : shallowWrapper => string = "name";

[@bs.send.pipe : shallowWrapper]
external forEach : (shallowWrapper => unit) => shallowWrapper = "forEach";

[@bs.send.pipe : shallowWrapper] external map : (shallowWrapper => 'a) => array('a) = "forEach";

[@bs.send.pipe : shallowWrapper]
external foldLeft : (('a, shallowWrapper) => 'a, 'a) => 'a = "reduce";

[@bs.send.pipe : shallowWrapper]
external foldRight : (('a, shallowWrapper) => 'a, 'a) => 'a = "reduceRight";

[@bs.get] external length : shallowWrapper => int = "length";

type adapter;

type js_obj_with_adapter = {. "adapter": adapter};

[@bs.module "enzyme"] external configure : js_obj_with_adapter => adapter = "configure";

[@bs.module] [@bs.new] external react_16_adapter : unit => adapter = "enzyme-adapter-react-16";

let configureEnzyme = (adapter: adapter) => configure({"adapter": adapter});
