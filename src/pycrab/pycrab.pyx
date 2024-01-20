cimport crab

cdef class Point:
    cdef crab.Point _point

    def __cinit__(self, int x, int y):
        self._point.x = x
        self._point.y = y
    
    def diff(self, Point other):
        return crab.point_diff(&self._point, &other._point)

    @property
    def x(self):
        return self._point.x

    @property
    def y(self):
        return self._point.y

    @x.setter
    def x(self, int value):
        self._point.x = value

    @y.setter
    def y(self, int value):
        self._point.y = value

cdef class Crab:
    cdef crab.Crab _crab

    def __cinit__(self, Point position, Point direction):
        self._crab.position = position._point
        self._crab.direction = direction._point

    def steps(self, Point target):
        return crab.crab_steps_to_target(&self._crab, &target._point)

    def can_reach(self, Point target):
        return crab.crab_can_reach(&self._crab, &target._point)

    @property
    def position(self):
        return self._crab.position

    @property
    def direction(self):
        return self._crab.direction

    @position.setter
    def position(self, Point value):
        self._crab.position = value

    @direction.setter
    def direction(self, Point value):
        self._crab.direction = value
