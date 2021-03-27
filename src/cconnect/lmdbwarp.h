#ifndef LMDB_WARP
#define LMDB_WARP

#include <lmdb.h>

namespace cconnect2 {
namespace cconnect {

class LmdbWarp {
public:
    LmdbWarp();
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