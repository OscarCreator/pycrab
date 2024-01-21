from pycrab import Point, Crab
import pytest


class TestCrab:

    @pytest.mark.parametrize("position, direction, target, expected", [
        (Point(0, 0), Point(1, 0), Point(5, 0), 5),
        (Point(0, 0), Point(0, 1), Point(0, 3), 3),
        (Point(0, 0), Point(1, 1), Point(5, 5), 5),
        (Point(0, 0), Point(2, 1), Point(2, 1), 1),
        (Point(0, 0), Point(1, 1), Point(2, 1), -1),
        (Point(0, 0), Point(2, 2), Point(2, 1), -1),
    ])
    def test_steps_to_target(self, position: Point, direction: Point,
                             target: Point, expected: int):
        crab = Crab(position, direction)
        assert crab.steps(target) == expected
