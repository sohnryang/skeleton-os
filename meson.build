project(
  'skeletonOS',
  'c',
  version : '0.0.0',
  default_options : ['warning_level=3']
)

inc = [include_directories('include')]
libc_source_files = []
project_header_files = [libc_source_files]
project_source_files = []
test_source_files = []

subdir('include')
subdir('linker-scripts')
subdir('src')
subdir('tests')

cmocka_proj = subproject('cmocka')
cmocka_dep = cmocka_proj.get_variable('cmocka_dep')

if meson.get_external_property('libc_only', false)
  libc = library(
    'c',
    libc_source_files,
    include_directories : inc,
  )

  testbin = executable(
    'testbin',
    test_source_files,
    include_directories : inc,
    dependencies : [cmocka_dep],
    link_with : [libc],
  )
  test('cmocka tests', testbin)
else
  os_bin = executable(
    'os.bin',
    project_source_files,
    include_directories : inc,
    link_args : [linker_script_flags, '-lgcc'],
    link_depends : linker_script_deps,
  )
endif
