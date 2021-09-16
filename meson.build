project(
  'skeletonOS',
  'c',
  version : '0.0.0',
  default_options : ['warning_level=3']
)

inc = [include_directories('include')]
project_header_files = []
project_source_files = []

subdir('include')
subdir('linker-scripts')
subdir('src')

os_bin = executable(
  'os.bin',
  project_source_files,
  include_directories : inc,
  link_args : [linker_script_flags, '-lgcc'],
  link_depends : linker_script_deps,
)
