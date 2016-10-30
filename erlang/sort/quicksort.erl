-module(quicksort).
-include_lib("eunit/include/eunit.hrl").

-export([start/0]).

% Quicksort implementation in Erlang
% https://en.wikipedia.org/wiki/Quicksort

% The simplest case is an empty list
% which would return an empty list
quicksort([])-> [];

% Quicksort takes an element as a pivot.
% Take the first element of the list (head) as pivot
quicksort([Pivot|Rest])->
  % Get all the items which are smaller and greater than our pivot
  Smallers = [Element || Element <- Rest, Element < Pivot],
  Greaters = [Element || Element <- Rest, Element >= Pivot],
  % Sort the smaller and greater lists recursevily
  % and append respectively the smallers, the pivot and the greaters list
  quicksort(Smallers) ++ [Pivot] ++ quicksort(Greaters).

start() ->
  Test1 = [4, 1, 2, 3, 9],
  Test2 = [1],
  Test3 = [2, 2, 1, -1, 0, 4, 5, 2],
  Test4 = [],
  ?assert(quicksort(Test1) =:= [1,2,3,4,9]),
  ?assert(quicksort(Test2) =:= [1]),
  ?assert(quicksort(Test3) =:= [-1,0,1,2,2,2,4,5]),
  ?assert(quicksort(Test4) =:= [0]).
