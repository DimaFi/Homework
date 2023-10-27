using System;
using System.IO;

namespace MyProgram
{
    struct SPoint
    {
        public int x, y, z;

        public SPoint(int x, int y, int z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public void Show()
        {
            Console.WriteLine("({0}, {1}, {2})", x, y, z);
        }

        public double Distance(SPoint other)
        {
            int dx = other.x - x;
            int dy = other.y - y;
            int dz = other.z - z;
            return Math.Sqrt(dx * dx + dy * dy + dz * dz);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            SPoint[] points = new SPoint[]
            {
                new SPoint(1, 2, 3),
                new SPoint(4, 5, 6),
                new SPoint(7, 8, 9),
                new SPoint(10, 11, 12)
            };

            SPoint minSumPoint = PointMinDistance(points);
            Console.WriteLine("Point min distan: ");
            minSumPoint.Show();
        }

        static SPoint PointMinDistance(SPoint[] points)
        {
            double minSumDistance = double.MaxValue;
            SPoint minSumPoint = new SPoint();

            for (int i = 0; i < points.Length; i++)
            {
                double sumDistance = 0;

                for (int j = 0; j < points.Length; j++)
                {
                    if (i != j)
                    {
                        sumDistance += points[i].Distance(points[j]);
                    }
                }

                if (sumDistance < minSumDistance)
                {
                    minSumDistance = sumDistance;
                    minSumPoint = points[i];
                }
            }

            return minSumPoint;
        }
    }
}
