const path = require('path');

module.exports = {
    mode: 'production',
    entry: './src/index.js',
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'duckdb_webapi_proto.js',
        libraryTarget: 'commonjs',
    },
    performance: {
        maxEntrypointSize: 512000,
        maxAssetSize: 512000,
    },
};

