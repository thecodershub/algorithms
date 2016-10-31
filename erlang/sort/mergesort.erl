-module(mergesort).
-include_lib("eunit/include/eunit.hrl").

-export([start/0]).

% Mergesort implementation in Erlang
% https://en.wikipedia.org/wiki/Mergesort

% # Auxiliary functions
%
% Trivial cases when either the left or right partitions
% don't need to be compared since the other is empty
mergesort(Left, []) -> Left;
mergesort([], Right) -> Right;
% If the first element (head) of the left partition is smaller, then
% place that element and mergesort the rest of the list with the right partition
% or the first element of the right with the mergesort of the left partition with
% the rest of the right partition
mergesort(Left, Right) ->
  [HeadLeft|TailLeft] = Left,
  [HeadRight|TailRight] = Right,
  if
    HeadLeft < HeadRight ->
      [HeadLeft | mergesort(TailLeft, Right)];
    true ->
      [HeadRight | mergesort(Left, TailRight)]
  end.

% # Trivial cases
% An empty list is a trivial case which is already ordered
mergesort([]) -> [];
% Another trivial case where a list with a single element is already ordered
mergesort([Element]) -> [Element];

% # Main mergesort function
%
mergesort([Head|Tail]) ->
  List = [Head|Tail],
  ListLength = length(List),
  % Partition the list in half
  % If the length of the list is odd, the right list is one element larger
  Middle = trunc(length(List)/2),
  Left = lists:sublist(List, Middle),
  Right = lists:sublist(List, Middle + 1, ListLength - Middle),
  % Recursevily mersesort both partitions
  OrderedLeft = mergesort(Left),
  OrderedRight = mergesort(Right),
  mergesort(OrderedLeft,OrderedRight).

start() ->
  Test1 = [4, 1, 2, 3, 9],
  Test2 = [1],
  Test3 = [2, 2, 1, -1, 0, 4, 5, 2],
  Test4 = [],
  ?assert(mergesort(Test1) =:= [1,2,3,4,9]),
  ?assert(mergesort(Test2) =:= [1]),
  ?assert(mergesort(Test3) =:= [-1,0,1,2,2,2,4,5]),
  ?assert(mergesort(Test4) =:= []).
