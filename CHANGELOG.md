# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [0.5.3][0.5.3] 2018-11-06

### Fixed

- Resolved a security vulerability affecting the project's `merge` dependency (see [CVE-2018-16469](https://nvd.nist.gov/vuln/detail/CVE-2018-16469))

## [0.5.2][0.5.2] 2018-10-03

### Fixed

- The README example no longer uses deprecated APIs (caught by [@lukashambsch](https://github.com/lukashambsch))

## [0.5.0: Full DOM Rendering][0.5.0] 2018-10-03

### Added

- Initial support for the `mount` API added by [@wezm](https://github.com/wezm)

### Changed

- ReasonReact dependency updated to `>=0.5.0`
- BuckleScript platform dependency updated to `>=4.0.0`

## [0.4.0: ReasonReact 0.3.x Support][0.4.0] - 2018-06-20

This release updates our ReasonReact dependency to 0.3.2. Thanks to @kolljohnson these improvements.

## [0.3.0: React 16 & Enzyme 3][0.3.0] - 2017-11-30

This release brings support for React 16 and Enzyme 3 thanks to @viebel's help. The README has been updated with examples of how to use the new adapter API.

## [0.2.0: Better State support][0.2.0] - 2017-08-30

## Breaking Changes

- The `Enzyme.getLength` function has been renamed to `Enzyme.length` for consistency #1
- The `props`, `propFor`, `setProps`, `state`, `stateFor`, `setState`, `context`, `contextFor`, and `setContext` functions have been renamed to `jsProps`, `jsPropFor`, `setJsProps`, `jsState`, `jsStateFor`, `setJsState`, `jsContext`, `jsContextFor`, and `setJsContext` respectively.

## New

- `Enzyme.foldLeft` and `Enzyme.foldRight` have been added as wrappers around `shallowWrapper`'s `reduce` and `reduceRight` methods.
- `Enzyme.state` now returns a component's `reasonState`

[unreleased]: https://github.com/olivierlacan/keep-a-changelog/compare/v0.5.3...HEAD
[0.5.3]: https://github.com/olivierlacan/keep-a-changelog/compare/v0.5.2...v0.5.3
[0.5.2]: https://github.com/olivierlacan/keep-a-changelog/compare/v0.5.0...v0.5.2
[0.5.0]: https://github.com/olivierlacan/keep-a-changelog/compare/v0.4.0...v0.5.0
[0.4.0]: https://github.com/olivierlacan/keep-a-changelog/compare/v0.3.0...v0.4.0
[0.3.0]: https://github.com/olivierlacan/keep-a-changelog/compare/v0.2.0...v0.3.0
[0.2.0]: https://github.com/olivierlacan/keep-a-changelog/compare/v0.1.1...v0.2.0
