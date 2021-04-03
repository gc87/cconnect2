#ifndef LMDB_WRAP
#define LMDB_WRAP

#include <lmdb.h>

namespace cconnect2 {
namespace cconnect {

class LmdbWarp {
public:
    LmdbWarp();

    int LmdbDrop();
    int LmdbPut();
    int LmdbGet();
    int LmdbDel();

    ~LmdbWarp();

private:
    MDB_env *   env;
    MDB_dbi     dbi;
    MDB_txn *   txn;
    MDB_cursor *cursor;
};

} // namespace cconnect
} // namespace cconnect2

#endif