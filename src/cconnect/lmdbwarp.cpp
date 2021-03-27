#include <iostream>
#include <lmdb.h>
#include "lmdbwarp.h"

namespace cconnect2 {
namespace cconnect {

LmdbWarp::LmdbWarp() {
    int rc;
    rc = mdb_env_create(&env);
    rc = mdb_env_open(env, "./testdb", 0, 0664);
    rc = mdb_txn_begin(env, NULL, 0, &txn);
    rc = mdb_dbi_open(txn, NULL, 0, &dbi);
}

} // namespace cconnect
} // namespace cconnect2