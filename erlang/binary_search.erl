-include_lib("eunit/include/eunit.hrl").

-module(binary_search).
-export([start/0]).

% Binary search implementation in Erlang
% https://en.wikipedia.org/wiki/Binary_search_algorithm


% Entrypoint that calls the function with an additional accumulator
% to save the index of the found element
binary_search(Haystack, Needle) ->
  binary_search(Haystack, Needle, 0).

binary_search(Haystack, Needle, PrevIndex) ->
  % Get the middle element
  HaystackLength = length(Haystack),
  Middle = (HaystackLength + 1) div 2,
  case Middle of
    % If there is no middle, the list is empty, so no element is found
    0 -> -1;
    _ ->
      % In any other case, get the element at the middle and compare it
      % with the element looked for
      Item = lists:nth(Middle,Haystack),
      case Item of
        % If it is the element looked for,
        % We return the sum of indexes and substract 1
        % Since it is a zero-based index search
        Item when Item =:= Needle ->
          PrevIndex + Middle - 1;
        % When the item is either greater or smaller than the
        % value looked for, search in the left or right lists
        % and also send the current index of the search
        Item when Item > Needle ->
          Left = lists:sublist(Haystack, HaystackLength - Middle),
          binary_search(Left, Needle, PrevIndex + Middle);
        Item when Item < Needle ->
          Right = lists:nthtail(Middle, Haystack),
          binary_search(Right, Needle, PrevIndex + Middle)
        end
  end.

start() ->
  Test1 = [1, 2, 3, 4, 6, 7, 9],
  Test2 = [-1, 0, 1, 5, 6, 9, 15, 15],
  Test3 = [-1, 0, 0, 0, 0, 1],
  Test4 = [],

  ?assert(binary_search(Test1,5) =:= -1),
  ?assert(binary_search(Test2,15) =:= 6),

  % Finding the left-most occurrence is not implemented
  % but it would find the element in the first iteration
  ?assert(binary_search(Test3,0) =/= -1),

  ?assert(binary_search(Test4, 10) =:= -1).
